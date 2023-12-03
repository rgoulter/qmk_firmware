# rgoulter's userspace.

### rules.mk options

- `CORNER_RESET_ENABLE` :: when `yes`, defines `CORNER_RESET_ENABLE`, which
  allows for entering the bootloader by holding all keys declared by the
  `boot_keypositions` array of col/row.

### CPP Defines

See `rgoulter.h` for the `#define`s.

- Tap-Holds, especially for thumb key clusters and home-row modifiers.

- Common keycode segments for building keymap layers.

- Desktop (Linux, macOS, Windows) shortcuts. (Cut/Copy/Paste, Lock screen, Desktop left/right).

- Custom keycodes: `OSLINUX`, `OSMACOS`, `OSWIN`, used by this userspace's `process_record_user`.

- (User-scoped) Combos: Desktop Left/Right, LEAD (Leader key sequence start).

#### Modifications to Miryoku-inspired Keymaps

- Base Alphabetical Layers:
  - Dvorak: retain semicolon, instead of using slash.
  - QWERTY: swap `'` and `/`.
    - Rationale:
      - Within the 3x10 grid:
        - Dvorak's symbol keys: `',.;`.
        - QWERTY's symbol keys: `,./;`.
      - Thus, Dvorak *needs* `/` on other layers, QWERTY *needs* `'` on other layers.
      - Instead, it's easier to swap `'` and `/` for QWERTY,
         so that it also needs `/` on other layers.
        - This allows pairing `/` with `\` on the Miryoku-style Number layer.
          (Whereas `'` doesn't have a similar complement).

### Implementation

#### `process_record_user`

- `bool process_record_keymap(uint16_t keycode, keyrecord_t *record)` is weakly
  defined, so that keymaps using this userspace can still customise behaviour of
  keycodes.

- Handles setting desktop (to Linux/macOS/Windows).

- If `CORNER_RESET_ENABLE` is defined, checks the `boot_keypositions` array;
  enters the bootloader once 4 of these have been pressed.

#### Combos

- `combo_t key_combos[COMBO_COUNT]`, `void process_combo_event_keymap(uint16_t combo_index, bool pressed)`
  are weakly defined, allowing for keymap reimplementation.

- (User-scoped) Combos: Desktop Left/Right, LEAD (Leader key sequence start).

#### Leader Key Sequences

- Q, B :: QMK Boot
- Q, E :: QMK EEPROM
- Q, H :: QMK Help
- Q, S :: QMK Status
- Q, D, D :: QMK Debug Disable
- Q, D, E :: QMK Debug Enable
- Q, D, T :: QMK Debug Toggle
- Q, D, K, D :: QMK Debug Keyboard Disable
- Q, D, K, E :: QMK Debug Keyboard Enable
- Q, D, K, T :: QMK Debug Keyboard Toggle
- C, C :: Caps capslock
- C, W :: Caps capsWord
- H, H :: Haptic DWIM (toggle)
- H, E :: Haptic Enable
- H, D :: Haptic Disable
- H, P :: Haptic Play
- H, T :: Haptic Toggle
- K, K :: Keymap DWIM (set to default)
- K, D :: Keymap Dvorak
- K, Q :: Keymap Qwerty
- K, G :: Keymap Gaming
- K, H :: Keymap Gaming (alt)
- O, W :: OS Windows
- O, L :: OS Linux
- O, M :: OS MacOS
- R, R :: RGB (DWIM)
- R, D :: RGB Disable
- R, E :: RGB Enable
- R, J :: RGB Jellybean
- R, N :: RGB Next effect
- R, P :: RGB Previous effect
- R, T :: RGB Toggle
- L :: Desktop Lock
