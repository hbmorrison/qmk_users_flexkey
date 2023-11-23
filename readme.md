# Flexkey Layout

## Introduction

This is a QMK layout designed with small split and unibody split keyboards in
mind, based on Colemak-DH and a core set of layers for symbols, numbers and
navigation keys situated in a 3x3 grid. The layout is designed to work with as
little as 18 keys with 2 thumb keys and can be expanded from there.

This git repository should be copied or cloned into the `users/flexkey/` folder
in the QMK firmware, or it can be added as a submodule. The `install_keymaps.sh`
script will install keymaps into several supported keyboards, which can then be
compiled. The `flexkey` keymap files are small and can be copied into other
keyboard keymap folders, and the exact configuration of the keymap can be
adjusted by editing variables in the `rules.mk` file. Almost all of the
functionality is defined in the `flexkey` userspace.

## Core Functionality

### Base Layer

![Base Layer](https://i.imgur.com/nLQrqOY.png)

![Expanded Keys](https://i.imgur.com/Xh5wUOa.png)

![Combo Keys](https://i.imgur.com/mH2OTHz.png)

### Extended Layers

![Left Extended Layer](https://i.imgur.com/FjGpWcJ.png)

![Right Extended Layer](https://i.imgur.com/PRYGj08.png)

### Symbol Layers

![Left Symbol Layer](https://i.imgur.com/VJQwVqO.png)

![Right Symbol Layer](https://i.imgur.com/l9g2RZT.png)

### Numbers and Navigation Layers

![Navigation Layer](https://i.imgur.com/mB7kndf.png)

![Number Layer](https://i.imgur.com/fN343YE.png)

### Shortcut Layer

![Shortcut Layer](https://i.imgur.com/hr0KIXp.png)

### Controls and Function Key Layers

![Controls Layer](https://i.imgur.com/pPfUDTk.png)

![Function Keys Layer](https://i.imgur.com/liex7sS.png)
