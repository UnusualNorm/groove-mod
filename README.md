# Groove Mod (name pending)

## Goal

The goal of this mod is to be a universal "importer" for the game. For now, that only includes:

- Remixes
- Sounds
- Wavmarks

However, I would eventually like it to also include:

- Beatspell Monsters/Quests
- Non-remix stages
- Comics
- Prologues
- Epilogues

## Design

I want this mod to be as simple as possible with very little hand holding, even at the cost of adding footguns. However, I am open to other people implementing basic sanity checks that I am currently missing.

## Example

There is an example re-implementation of Remix 1 in the `example` folder. It should overwrite the original remix 1, but be indistinguishable from it. (You can tell its running by looking at the debug output)

## Gachas

- When calling `stage:setEpilogueAndRatings`, ensure that the strings you pass are not collected until `Destroy` is called. I haven't verified that it actually is an issue, but the game does store the raw pointers. I have `luaG_leakstring` to help with this, but I haven't found a way to neatly integrate it.
- If the lua crashes, it will just cause the game to hang in a broken stage if pausing isn't enabled. This could be easily fixed by just forcing the game back to the menu, but I haven't convinced myself that this is a good idea yet.

## TODOS

- Remove all C code, replace with C++ (I'm looking at you, `luag`)
- Get basic cues defined for all scenes
- Custom menu for selecting custom stages
- Change all symbols to use non-mangled names

## AI

I am not an anti-AI activist, but AI should not be a shortcut for understanding code. If AI generates code that you cannot (or cannot come to) fully understand, then in most cases you should not be using it.

Now, with that said, I will be transparent in where I have used AI during this project.

1. [swig_lua.py](swig_lua.py) - Perhaps the most egregious use. I got lazy here and deemed that it would take too long for me to implement this generator by-hand.
2. `example/thread/89_cues*.lua` - After transcribing entry, anim, and control threads directly from ghidra, the task of transcribing and keeping track of all of that ghidra output into lua was too daunting for me. I had it squash all of the waits together and remove (what I deemed to be) useless function calls so I could have an easier time transcribing.
3. I used AI in ghidra to give me overviews of how/what functions achieve certain end results. This did not supplant my own understanding of the code, but it did help me to understand it faster via "guessing" and checking.
