let pkgs = import /home/adjective/Projects/nixpkgs/default.nix {};
in with pkgs; let
# build tools
  dependencies = [
    SDL2
    SDL2_image
    SDL2_ttf
    SDL2_gfx
    libyamlcpp
    boost
    glibc
    glm
    mesa
    libdrm
    lzma
    xorg.libpciaccess
    assimp
  ];

  devDependencies = [
    cmake
    cppcheck
    llvmPackages.clang-unwrapped
    gdb
    valgrind
    pkgconfig
    clang-tools
    gmock
    zsh
    patchelf
  ];

in stdenv.mkDerivation {
  name = "sdl2game";
  buildInputs = dependencies ++ devDependencies;
  shellHook = ''
    export GTEST_DIR=${gtest}
    export LIBCXX_DIR=${libcxx}
    export PCI_DIR=${xorg.libpciaccess}
  '';
}

