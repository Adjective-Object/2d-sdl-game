let pkgs = import <nixpkgs> {};
in with pkgs; let
# build tools
  dependencies = [
    SDL2
    SDL2_image
    SDL2_ttf
  ];

  devDependencies = [
    cmake
    cppcheck
    llvmPackages.clang-unwrapped
    gdb
    valgrind
    pkgconfig
  ];

in stdenv.mkDerivation {
  name = "sdl2game";
  buildInputs = dependencies ++ devDependencies;
}

