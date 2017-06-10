# SDL-Game

An sdl platformer that's a lot like melee but not quite.

## Setup

#### NixOs / Ubuntu

This project uses nix to manage dependencies. Because nix does not
manage opengl directly on non-nixos systems, a setup script is
provided to setup & patch the drivers into the locations expected by
the nix-managed mesa. Steps are:

1. Install nix
2. run `nix-shell` in the project directory
3. If running nix on top of Ubuntu, run `./setup.sh`

#### OSX

Only tested on Sierra (10.12.5 (16F73)).

1. Install cli tools with xcode select
    `xcode-select install`
2. Install brew
3. Install dependencies with brew
    ```
    brew install cmake sdl2 sdl2_gfx sdl2_ttf  sdl2_image \
        yaml-cpp glm assimp gl pkg-config
    ```

## Compilation

The project uses CMake in order to build. Compilation steps are:

```
mkdir build
cd build
cmake ..
make
```

or just

```
make
```

