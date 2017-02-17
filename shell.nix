let pkgs = import <nixpkgs> {};
in with pkgs; let
# build tools
  dependencies = [
    SDL2
    SDL2_image
    SDL2_ttf
    SDL2_gfx
    mesa
    libyamlcpp
    boost
  ];

  devDependencies = [
    cmake
    cppcheck
    llvmPackages.clang-unwrapped
    gdb
    valgrind
    pkgconfig
    clang-tools
  ];

in stdenv.mkDerivation {
  name = "sdl2game";
  buildInputs = dependencies ++ devDependencies;
}

