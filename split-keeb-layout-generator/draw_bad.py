#! /usr/bin/env python3

from sys import argv, stdout
from pprint import pprint
import logging
from importlib import import_module

# check for arguments, and use the first one as a keymap if possible
if len(argv) > 1:
    KEYMAP = import_module(argv[1]).KEYMAP
else:
    from keys_34.keymap_34 import KEYMAP

# define key-related dimensions
KEY_W = 60
KEY_H = 45
KEY_RX = 6
KEY_RY = 6
INNER_PAD_W = 4
INNER_PAD_H = 4
OUTER_PAD_W = KEY_W / 2
OUTER_PAD_H = KEY_H / 2
LINE_SPACING = 20

STYLE = """
    svg {
        font-family: SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace;
        font-size: 14px;
        font-kerning: normal;
        text-rendering: optimizeLegibility;
        fill: #24292e;
    }

    rect {
        fill: #f6f8fa;
    }

    .hold {
        fill: #ff8080;
    }

    .combo_hold {
        fill: #ff8080;
    }

    .combo {
        fill: #79f2f2;
    }
    
    .number{
        fill: #bfc2c7
    }

    .invisible{
        opacity: 0;
    }
"""


# count the number of layers in the keymap
layers = 0

for layer in KEYMAP:
    layers += 1

padding = layers + 1


# count the number of rows in a layer
# rows = 1

# for layer in KEYMAP:
#     for row in layer["left"]:
#         rows += 1
#     break

rows = len(list(KEYMAP[0].values())[0])

# count of the number of columns in the first side (not working)
# cols = len(KEYMAP[0]["left"][0])
cols = len(list(KEYMAP[0].values())[0][0])

board_type = "split" if str(list(KEYMAP[0].keys())[0]) == "left" else "unibody"

# define dimensions for svg components
KEYSPACE_W = KEY_W + 2 * INNER_PAD_W
KEYSPACE_H = KEY_H + 2 * INNER_PAD_H
HAND_W = cols * KEYSPACE_W
HAND_H = rows * KEYSPACE_H
LAYER_W = 2 * HAND_W + OUTER_PAD_W
LAYER_H = HAND_H
BOARD_W = LAYER_W + 2 * OUTER_PAD_W if board_type == "split" else (LAYER_W + 2 * OUTER_PAD_W) / 2 + OUTER_PAD_W
BOARD_H = layers * LAYER_H + padding * OUTER_PAD_H


def print_key(x, y, key, combo_flag):
    key_class = "" # placeholder for class value
    key_width = 1 # default key width is 1U

    if type(key) is dict:
        if "width" in key:
            key_width = float(key["width"])
            # key = key["key"]
        key_class = key["class"]
        key = key["key"]
        
    width_of_key = (KEY_W * key_width)

    # print key shape
    print(
        f'<rect rx="{KEY_RX}" ry="{KEY_RY}" x="{x + INNER_PAD_W}" y="{y + INNER_PAD_H}" width="{width_of_key}" height="{KEY_H}" class="{key_class}" />'
    )

    if "invisible" in key_class:
        key = ""

    # prepare text
    words = key.split()
    y += (KEYSPACE_H - (len(words) - 1) * LINE_SPACING) / 2

    # prints text on key
    for word in key.split():
        print(
            f'<text text-anchor="middle" dominant-baseline="middle" x="{x + KEYSPACE_W / 2}" y="{y}">{word}</text>'
        )
        y += LINE_SPACING

    # print combo arc if past two keys are combos
    if "combo" in key_class:
        if combo_flag:
            print(
                f'<path fill="none" stroke="#5656A8" stroke-width="4" stroke-linecap="round" d="M{x+OUTER_PAD_W},{y-KEY_H+INNER_PAD_H*6} A{KEY_W},{KEY_W*1} 0,0,0 {x-OUTER_PAD_W},{y-KEY_H+INNER_PAD_H*6}" />'
            )


def print_row(x, y, row):
    for index,key in enumerate(row):

        now_combo = False # flag when the current key is a combo
        combo_flag = False # flag when th current and previous keys are combos
        
        # placeholders for class values
        key_class = ""
        prev_class = ""
        
        # if there's a key class, get it
        if type(key) is dict:
            key_class = key["class"]
        
        # flag if the key is a sort of combo
        if "combo" in key_class:
            if index > 0:
                prev = row[index-1]
                now_combo = True
        
        # check if the previous keys is also a combo key
        if now_combo:
            if type(prev) is dict:
                prev_class = prev["class"]
            if "combo" in prev_class:
                combo_flag = True

        # print the key and track space
        print_key(x, y, key, combo_flag)
        
        keyspace = (KEY_W * float(key["width"])) + 2 * INNER_PAD_W if ((type(key) is dict) and ("width" in key)) else KEYSPACE_W
        x += keyspace


def print_block(x, y, block):
    for row in block:
        print_row(x, y, row)
        y += KEYSPACE_H


def print_layer(x, y, layer):
    if board_type == "split":
        # print left then right blocks
        print_block(x, y, layer["left"])
        print_block(
            x + HAND_W + OUTER_PAD_W, y, layer["right"],
        )

        # count the number of rows in the blocks
        # rows = 0

        # for row in layer["left"]:
        #     rows += 1

        # print the thumbs below the main blocks
        # account for thumb count and row count in thumb placement
        print_row(
            x + (cols-len(layer["thumbs"]["left"])) * KEYSPACE_W, y + rows * KEYSPACE_H, layer["thumbs"]["left"],
        )
        print_row(
            x + HAND_W + OUTER_PAD_W, y + rows * KEYSPACE_H, layer["thumbs"]["right"],
        )
    else:
        # print a unibody keyboard
        print_block(x, y, layer["unibody"])


def print_board(x, y, keymap):
    x += OUTER_PAD_W
    for layer in keymap:
        y += OUTER_PAD_H
        print_layer(x, y, layer)
        y += LAYER_H


print(
    f'<svg width="{BOARD_W}" height="{BOARD_H}" viewBox="0 0 {BOARD_W} {BOARD_H}" xmlns="http://www.w3.org/2000/svg">'
)
print(f"<style>{STYLE}</style>")
print_board(0, 0, KEYMAP)
print("</svg>")

