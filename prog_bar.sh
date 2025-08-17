#!/bin/bash

# bar compilation
gcc ./sources/bar.c -o bar

# program compilation
gcc ./sources/bun.c -o bun
gcc ./sources/salad.c -o salad
gcc ./sources/tomato.c -o tomato
gcc ./sources/hamburger.c -o hamburger

# progressive bar and installation process
./bar 0
./bun 
./bar 20
./tomato 
./bar 40
./salad 
./bar 60
./hamburger 
./bar 80
./bun 
./bar 100
rm bar
clear
