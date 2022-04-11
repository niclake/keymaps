# Nic Lake's Boardwalk Layout

This is Nic's Boardwalk layout, which is based off of the default Pok3r layout.

## Notes:

- QWERTY base layer with Colemak support
- QWERTY bottom row set up for Mac usage (use `MACWIN`/`AG_TOGG` to toggle)
- Latching Numpad layer for data entry (press NUM key twice to latch)
- Uses [Space Cadet shift keys](https://docs.qmk.fm/#/feature_space_cadet?id=usage)

## How To:

- `qmk setup` to make sure we're current on everything
- `qmk clean -a` to clear out my `.build` folder
- `qmk compile -kb boardwalk -km niclake` to compile
- Launch QMK Toolbox, and point it at the `boardwalk_niclake.hex` file in the `qmk` folder
- Unplug board, hold Space + B, and plug board back in. Should see `Atmel DFU device connected: ATMEL ATm32U4DFU` in QMK Toolbox
- Flash the board
