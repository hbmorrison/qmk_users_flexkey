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

![Base Layer](https://imgur.com/PMj8RcF)

![Expanded Keys](https://imgur.com/EJFFU1D)

![Combo Keys](https://imgur.com/lFbG5OJ)

### Extended Layers

![Left Extended Layer](https://imgur.com/CIfiREC)

![Right Extended Layer](https://imgur.com/f7jQQks)

### Symbol Layers

![Left Symbol Layer](https://imgur.com/qbKbRoE)

![Right Symbol Layer](https://imgur.com/4nGDk28)

### Numbers and Navigation Layers

![Navigation Layer](https://imgur.com/SmcMxuX)

![Number Layer](https://imgur.com/wxQAttu)

### Shortcut Layer

![Shortcut Layer](https://imgur.com/kGkNnge)

### Controls and Function Key Layers

![Controls Layer](https://imgur.com/924aGdG)

![Function Keys Layer](https://imgur.com/nK6Pbla)
