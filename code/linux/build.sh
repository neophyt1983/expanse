#!/bin/bash

# Build Tools
gcc main.c -o Expanse $(pkg-config --cflags --libs sdl2)  -Wall -lX11 -lncurses -lSDL2_image -lm
