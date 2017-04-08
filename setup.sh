#!/usr/bin/env bash

set -e

sudo rm -rf nix_libs
mkdir -p ./nix_libs
rsync -aszvi /usr/lib/x86_64-linux-gnu/mesa/libGL.* ./nix_libs/
# rsync -aszvi /usr/lib/x86_64-linux-gnu/mesa/* ./nix_libs
# rsync -aszvi /usr/lib/x86_64-linux-gnu/libdrm* ./nix_libs/
rsync -aszvi /usr/lib/x86_64-linux-gnu/dri/i965_dri.so ./nix_libs/dri/

for x in $(find ./nix_libs \! -type l | grep '\.so' | grep -v .conf); do
    echo "patching $x"
    sudo chmod 777 $x
    patchelf --set-rpath /lib:/usr/lib:/lib/x86_64-linux-gnu:/usr/lib/x86_64-linux-gnu $x
done

ln -s $PCI_DIR/lib/*.so* ./nix_libs/

sudo rm -rf /run/opengl-driver
sudo mkdir -p /run/opengl-driver/lib
sudo ln -s $(pwd)/nix_libs/* /run/opengl-driver/lib


