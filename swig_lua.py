# SLOP SLOP SLOP SLOP
# This is LLM generated code. Reading and understanding megabyte-large xml files is not my forte, so I gave up.
# Mark my words, I will rewrite this at some point in the future, but for now, this works and is good enough.

import logging
import re
import sys
import xml.etree.ElementTree as ET
from collections import defaultdict
from pathlib import Path


def attrs(node):
    return {
        a.get("name"): a.get("value") for a in node.findall("./attributelist/attribute")
    }


def main():
    root = ET.parse(sys.argv[1]).getroot()
    module = attrs(root)["module"]
    classes = list(root.iter("class"))
    names = {attrs(c)["name"]: f"{module}.{attrs(c)['sym_name']}" for c in classes}
    short = defaultdict(set)
    for cpp, lua in names.items():
        short[cpp.rsplit("::", 1)[-1]].add(lua)

    def class_name(cpp):
        matches = short[cpp.rsplit("::", 1)[-1]]
        return names.get(cpp) or (next(iter(matches)) if len(matches) == 1 else None)

    def lua_type(base, decl="", where=""):
        raw = base or "void"
        t = re.sub(r"q\([^)]*\)\.", "", raw)
        t = re.sub(r"^(?:p\.|r\.)+", "", t)
        pointer = raw.startswith(("p.", "r.")) or decl.startswith(("p.", "r."))
        if decl.startswith("a("):
            result = "any"
        elif t == "char" and pointer:
            result = "string"
        elif t == "bool":
            result = "boolean"
        elif t == "void" and not pointer:
            result = "nil"
        elif t == "float":
            result = "number"
        elif t in ("int", "unsigned int", "unsigned char", "char"):
            result = "integer"
        else:
            result = class_name(t) or "any"
        if result == "any":
            logging.warning("%s: %s (decl=%s) resolved to any", where, raw, decl)
        return result

    def params(node, where):
        result = []
        for i, p in enumerate(node.findall("./attributelist/parmlist/parm"), 1):
            a = attrs(p)
            if a.get("tmap_in_numinputs") == "0":
                continue
            name = a.get("name") or f"arg{i}"
            result.append(
                (name, lua_type(a.get("type"), a.get("decl") or "", f"{where}.{name}"))
            )
        return result

    def signature(pp, ret="nil"):
        return f"fun({', '.join(f'{n}: {t}' for n, t in pp)})" + (
            f": {ret}" if ret != "nil" else ""
        )

    out = ["---@meta", f"---@class {module}", f"{module} = {{}}"]
    fields = methods_count = 0
    for c in classes:
        a = attrs(c)
        full = names[a["name"]]
        bases = list(
            dict.fromkeys(
                filter(
                    None,
                    (
                        class_name(b.get("name", ""))
                        for b in c.findall("./attributelist/baselist/base")
                    ),
                )
            )
        )
        out.append(
            f"---@class {full}"
            + (f" : {', '.join(b for b in bases if b != full)}" if bases else "")
        )
        methods, ctors = {}, []
        for e in (
            list(c.findall("cdecl"))
            + list(c.findall("constructor"))
            + list(c.findall("./extend/cdecl"))
        ):
            ea = attrs(e)
            name = ea.get("lua_name") or ea.get("sym_name") or ea.get("name")
            if e.tag == "constructor":
                ctors.append(params(e, f"{full}.new"))
            elif ea.get("kind") == "variable":
                out.append(
                    f"---@field {name} {lua_type(ea.get('type'), ea.get('decl') or '', f'{full}.{name}')}"
                )
                fields += 1
            elif ea.get("kind") == "function":
                decl = ea.get("decl") or ""
                ret_decl = decl.rsplit(").", 1)[-1] if ")." in decl else ""
                ret = lua_type(ea.get("type"), ret_decl, f"{full}.{name} return")
                methods.setdefault(name, []).append(
                    (params(e, f"{full}.{name}"), ret, ea.get("storage") == "static")
                )
        for pp in ctors:
            out.append(f"---@overload {signature(pp, full)}")
        out.append(f"{full} = {{}}")
        for name, overloads in methods.items():
            pp, ret, static = overloads[0]
            out.extend(f"---@overload {signature(p, r)}" for p, r, _ in overloads[1:])
            out.extend(f"---@param {n} {t}" for n, t in pp)
            if ret != "nil":
                out.append(f"---@return {ret}")
            out.extend(
                (
                    f"function {full}{'.' if static else ':'}{name}({', '.join(n for n, _ in pp)}) end",
                    "",
                )
            )
            methods_count += 1
        out.append("")
    output = Path(sys.argv[2])
    output.write_text("\n".join(out) + "\n")
    print(
        f"Wrote {output}: {len(classes)} classes, {fields} fields, {methods_count} methods"
    )


if __name__ == "__main__":
    main()
