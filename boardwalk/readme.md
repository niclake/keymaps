# Nic Lake's Boardwalk Layout

This is Nic's Boardwalk layout

## Notes

- QWERTY base layer (for Macs) w/ Colemak support (for Windows)
- Latching Numpad layer for data entry (press NUM key twice to latch)
- Uses [Space Cadet shift keys](https://docs.qmk.fm/#/feature_space_cadet?id=usage)
- Experimenting with [Home Row Mods](https://precondition.github.io/home-row-mods)

## To compile with Vial

My Boardwalk is currently set up to use [Vial](https://get.vial.today) as its firmware. Running the Vial software w/ the keyboard plugged in should allow you to see and edit the layouts accordingly. You can follow the directions below to re-compile the firmware if necessary.

- Use the [Vial porting instructions](https://get.vial.today/docs/porting-to-vial.html)
- Clone the Vial QMK fork
- Copy this dz60 folder into /vial-qmk/keyboards/boardwalk/keymaps/vial/
- From vial-qmk root, run `make boardwalk:vial`
- If you're unable to put the board into bootloader mode via a `RESET` code, plug the board in while holding either `ESC` or `SPACE + B` (can't remember which one it is)

## QMK option

- `qmk setup` to make sure we're current on everything
- `qmk clean -a` to clear out my `.build` folder
- `qmk compile -kb boardwalk -km niclake` to compile
- Launch QMK Toolbox, and point it at the `boardwalk_niclake.hex` file in the `qmk` folder
- Unplug board, hold Space + B, and plug board back in. Should see `Atmel DFU device connected: ATMEL ATm32U4DFU` in QMK Toolbox
- Flash the board
