// Graphics module

/*
    6502ASM Display diagram
    YYYY = VIEW/EDIT
    xx = Most significant Byte
    XX = Byte

    |------------------------------------------------------------------------------------|
    | |--------------------------------------------------------|  |--------------------| |
    | | Memory (1)                                       (YYYY)|  | Registers (2)      | |
    | |--------------------------------------------------------|  |--------------------| |
    | | ADDR | 0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F  |  | PC XXXX            | |
    | | xx00 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | XXXXXXXXXXXXXXXX   | |
    | | xx10 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | p  XX              | |
    | | xx20 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | XXXXXXXX           | |
    | | xx30 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | SP XX    X  XX     | |
    | | xx40 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | XXXXXXXX XXXXXXXX  | |
    | | xx50 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | A XX     Y  XX     | |
    | | xx60 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | XXXXXXXX XXXXXXXX  | |
    | | xx70 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |--------------------| |
    | | xx80 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  | Disassembler (3)   | |
    | | xx90 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |--------------------| |
    | | xxA0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | | xxB0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | | xxC0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | | xxD0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | | xxE0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | | xxF0 | XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX |  |                    | |
    | |--------------------------------------------------------|  |--------------------| |
    |                                                                                    |
    | |-------------|-------------|-------------|------------|------------|------------| |
    | |     Run     |    Reset    |  Interrupt  |    Edit    |    Range   |    Load    | |
    | |-------------|-------------|-------------|------------|------------|------------| |
    |------------------------------------------------------------------------------------|
*/

#pragma once

#include <gint/display.h>

#include "mos6502.h"
#include "compiler.h"

extern const font_t gint_font5x7;

void setupHome(mos6502 mpu, uint8_t* memory);

void drawMemory(uint8_t* memory, uint16_t startAddress, uint16_t programCounter);

void drawRegisters(mos6502 mpu);

void drawDisassembler(uint8_t* memory, uint16_t address, uint16_t programCounter);

void drawWindow();
