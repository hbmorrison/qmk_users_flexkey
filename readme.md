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

The base layer is made up of the middle three columns of a Colemak DH layout.
Most of the keys also operate as modifiers or layer keys if held down. There are
a number of ways to access the rest of the Colemak DH keys. The first way is to
use the extended layers, accessed with the middle `S` and `E` keys.

![Left Extended Layer](https://i.imgur.com/FjGpWcJ.png)

![Right Extended Layer](https://i.imgur.com/PRYGj08.png)

The `S` key makes the outer columns on the right side of the keyboard available
and the `E` key makes the outer columns on the left side of the keyboard
available.

The second way is to use combos.

![Combo Keys](https://i.imgur.com/mH2OTHz.png)

Combos make the outer keys available by pressing two adjacent keys at the same
time.

The final way is to use a larger keyboard (most keyboards) and expand the keymap
to use them, by setting variables in the `rules.mk` file.

![Expanded Keys](https://i.imgur.com/Xh5wUOa.png)

The following variables are available:

- **FK_TOP_OUTER_KEY = yes** enables the `Q` and `Backspace` keys
- **FK_MIDDLE_OUTER_KEY = yes** enables the `A` and `O` keys
- **FK_BOTTOM_OUTER_KEY = yes** enables the `Z` and `/` keys
- **FK_INNER_KEYS = top** enables the `B`, `J`, `G` and `M` keys
- **FK_INNER_KEYS = bottom** enables the `G`, `M`, `V` and `K` keys
- **FK_INNER_KEYS = all** enables all of the `B`, `J`, `G`, `M`, `V` and `K`
  keys

As physical keys become available the combos for those keys are disabled unless
the following variable is defined:

- **FK_COMBOS_ON = yes** enables all combos regardless of which physical keys
  are defined

Finally the number of thumb keys per side can be increased:

- **FK_TWO_THUMBKEYS = yes** enables two thumb keys per side of the keyboard

Modifiers are organised vertically on the outside columns so that they can be
pressed along with the extended layer keys, `S` and `E`.

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
