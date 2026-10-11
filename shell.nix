{
  pkgs ? import <nixpkgs> { },
}:
let
  sys = import ./sys/nix pkgs;
in
pkgs.mkShell.override
  {
    stdenv = pkgs.llvmPackages.libcxxStdenv;
  }
  {
    buildInputs = sys.dependencies;
    packages = with pkgs; [
      cmake
      llvmPackages.clang-unwrapped
    ];
  }
