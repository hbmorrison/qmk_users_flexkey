# Flexkey Layout

## Introduction

This is a QMK layout designed with small split and unibody split keyboards in
mind, based on Colemak-DH and a core set of layers for symbols, numbers and
navigation keys situated in a 3x3 grid. The layout is designed to work with as
little as 18 keys with 2 thumb keys and can be expanded from there.

## Usage

This git repository should be copied or cloned into the `users/flexkey/` folder
in the QMK firmware, or it can be added as a submodule. The `install_keymaps.sh`
script will install keymaps into several supported keyboards, which can then be
compiled. The `flexkey` keymap files are small and can be copied into other
keyboard `keymap/` subfolders, and the exact configuration of the keymap can be
adjusted by editing variables in the `rules.mk` file.

## Core Functionality

![Base Layer](https://i.imgur.com/nLQrqOY.png)

The base layer is made up of the middle three columns of a Colemak-DH layout.
Most of the keys also operate as modifiers or layer keys if held down. In
addition, the shortcut layer can be accessed by tapping the two thumb keys at
the same time, and the QMK Caps Word feature can be toggled by tapping the two
shift modifier keys at the same time.

![Default Combo Keys](https://i.imgur.com/2vaVXIW.png)

There are a number of ways to access the rest of the Colemak-DH keys. The first
way is to use the extended layers, accessed with the middle `S` and `E` keys.

![Left Extended Layer](https://i.imgur.com/a6SBT3U.png)

![Right Extended Layer](https://i.imgur.com/k1ppSYW.png)

The `S` key makes the outer columns on the right side of the keyboard available
and the `E` key makes the outer columns on the left side of the keyboard
available.

The modifier keys are organised vertically on the outside columns so that they
can be pressed along with the extended layer keys. The extended layers also
define the corresponding modifier keys in the same places, so you can be relaxed
about whether you hold down modifiers before or after the layer key.

The second way is to use combos.

![Combo Keys](https://i.imgur.com/1hmz6D1.png)

Combos make the outer keys available by pressing two adjacent keys at the same
time. For example, `K` is accessed by pressing the `H` and `Comma` keys
together.

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

- **FK_TWO_THUMBKEYS = yes** enables two thumb keys per side of the keyboard,
  adding `Shift` and `Backspace` thumb keys alongside `Space` and `Enter`.

## Other Layers

### Symbol Layers

Both symbol layers put the symbols associated with the shifted number keys on
the top row, in their correct finger positions as much as possible.

 ![Left Symbol Layer](https://i.imgur.com/PKImXjQ.png)

The left symbol layer gathers the pairs of symbols that would normally appear on
the right side of a standard UK ISO keyboard.

![Right Symbol Layer](https://i.imgur.com/sZ8cSr1.png)

The right symbol layer gathers the brackets, braces and parentheses. The
backslash and pipe symbols appear on the left, echoing where that key appears on
a UK ISO keyboard.

### Numbers and Navigation Layers

![Navigation Layer](https://i.imgur.com/mB7kndf.png)

The navigation layer gathers navigation related keys together. The right side of
the layer has the arrow keys and related keys, along with some useful navigation
macros. The left side has the three non-alphanumeric keys found on the left of a
standard keyboard - `Esc`, `Tab` and `Caps Lock` - as well as modified `Tab`
keys for convenience.

![Number Layer](https://i.imgur.com/fN343YE.png)

The number layer arranges the number keys in keypad format on the left side (I'm
left-handed). Some useful keys are replicated on the right side of the layers.

### Controls and Function Layers

The controls and function layers gather together media keys and function keys
respectively.

![Controls Layer](https://i.imgur.com/EjEdnBC.png)

![Function Layer](https://i.imgur.com/1pMgyaz.png)

The function layer also has keys for the left and right mouse buttons, which can
be used with a trackball operated by your left thumb.

### Shortcut Layer

Finally the shortcut layer provides a number of macros to work with applications
on Windows and ChromeOS. This layer is tailored to my work and may be of limited
use to other people without modifications.

The Windows macros mostly rely on an AutoHotkey script (included in this repo)
whereas on ChromeOS applications are launched based on their postion on the
shelf - you can think of the four app keys as "launch shelf app 1" and so on.

The 1Password Shift-Ctrl-Space keyboard shortcut is used on Windows, whereas on
ChromeOS the browser will be opened and Shift-Ctrl-X will be issued to open the
1Password browser extension (this may need to be configured in your extension
settings).

By default the keyboard will start in Windows mode, but the mode can be changed
at any time with the `Win` and `CROS` keys.

![Shortcut Layer](https://i.imgur.com/hr0KIXp.png)

The shortcut layer is activated using a combo, by pressing the `Space` and
`Enter` keys at the same time. The layer is also activated if one of those keys
is pressed while the other is held down, so you can be relaxed about exactly how
the keys are pressed.
