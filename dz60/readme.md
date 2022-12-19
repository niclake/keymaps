# Nic Lake's DZ60 Layout

This is Nic's DZ60 layout.

## General information

- QWERTY base layer (for Macs) w/ Colemak support (for Windows)
- Uses [Space Cadet shift keys](https://docs.qmk.fm/#/feature_space_cadet?id=usage)
- Experimenting with [Home Row Mods](https://precondition.github.io/home-row-mods)

## To compile

My DZ60 is currently set up to use [Vial](https://get.vial.today) as its firmware. Running the Vial software w/ the keyboard plugged in should allow you to see and edit the layouts accordingly. You can follow the directions below to re-compile the firmware if necessary.

- Use the [Vial porting instructions](https://get.vial.today/docs/porting-to-vial.html)
- Clone the Vial QMK fork
- Copy this dz60 folder into /vial-qmk/keyboards/dztech/dz60rgb_ansi/v2_1/keymaps/vial/
- From vial-qmk root, run `make dztech/dz60rgb_ansi/v2_1:vial`
- If you're unable to put the board into bootloader mode via a `RESET` code, plug the board in while holding either `ESC` or `SPACE + B` (can't remember which one it is)