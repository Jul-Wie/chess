#!/bin/sh

g++ -o bin/debug/out.bin main.cpp pieces.cpp && ./bin/debug/out.bin && rm bin/debug/out.bin
