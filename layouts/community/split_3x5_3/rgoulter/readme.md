A Miryoku-inspired keymap, with adjustments for Dvorak base/default alphabetical
layout.

SEE ALSO: userspace, for some functionality this keymap benefits from.

## Keyboards

The split-3x5+3 layout is suitable for keyboards which have at least 3 thumb
keys on each side.

I use this with the [MiniF4-36](https://github.com/rgoulter/keyboard-labs#x-1-36-key-split-reversible-pcb-with-weact-studio-mini-f4-dev-board), [Pico42](https://github.com/rgoulter/keyboard-labs?tab=readme-ov-file#pico42-simple-hand-solderable-pcb-in-bm40jj40-form-factor) and [PyKey40HSRGB](https://github.com/rgoulter/keyboard-labs#pykey40-hsrgb-4x12-ortholinear-with-hotswap-and-rgb-in-bm40jj40-form-factor) keyboards.

## Layers

- "Base" alphabetical layers: Dvorak, QWERTY.

- A "check" layer, to help check each key in the keyboard has been soldered correctly.

- A "childproof" layer, for keyboard mashing.

- Miryoku-style layers: Number, Symbol, Function, Nav, Mouse, Media

- Game (Default, Alt) for playing the classic Tomb Raider games.

## Modifications to Miryoku

- Thumb keys:
  - LHS thumb keys: {Tab, Esc, Spc} instead of {Esc, Spc, Tab}
  - RHS thumb keys can be: {Bksp, Ent, Del} instead of {Ent, Bksp, Del}
    - Controlled by `RHS_THUMB_MEDIAL_ENABLE` in `rules.mk`,
      or whether `RHS_THUMB_MEDIAL` is `#define`d in `config.h`.
      - "Medial" = closer to body's middle.
      - e.g. on Pico42 (or when using 3 thumbkeys on ortho5x12),
        I find it more comfortable to have the 'third key' for RHS be more medial,
        so that the main two RHS thumb keys are below 'nm'.

- Base Alphabetical Layers: see userspace readme.

- Nav, Mouse layers:
  - Not implemented: the convenience cut/copy/paste and undo/redo

- Media layer:
  - No Bluetooth functionality/keycodes.
  - Bottom row: used to swap base/default layers, and enter the bootloader.
  - RGB modifier keys don't follow Nav swap to vi-style.

- Number/Symbol layers:
  - Affected by changes to the base/default alphabetical keymap.
    - `` ` ``/`~` in middle row.
    - `/`/`?` (rather than `;`/`:`).

## Custom Keycodes

- Inherited from userspace.

- None added.

## Combos (Chords)

- Inherited from userspace.

- None added.

## Leader Key Sequences

- Inherited from userspace.

- None added.

## Keyboard Hardware Features

For keyboards which support these features (the MiniF4-36 supports these):

- RGB Matrix
  - Keycodes on Nav layer manipulate RGB matrix (same as Mirkoyu).
  - Per userspace, some leader key sequences also manipulate RGB matrix.

- Rotary Encoders:
  - I haven't been inspired to use them.

- OLED screen:
  - I copied Bongo Cat over.
  - I don't really look at my keyboard.

- Haptic feedback, solenoid:
  - Works, but haven't yet found good use for a plain solenoid.

