#include <gint/display.h>
#include <gint/keyboard.h>

#include "mos6502.h"
#include "computer.h"
#include "graphics.h"

#include <stdio.h>
#include <cstring>

using namespace std;

uint8_t prgm[] = {0xa9, 0x01, 0x6a, 0x4c, 0x02, 0x00};

uint8_t mem[0xffff] = { 0x00 };

uint8_t read(uint16_t addr) {
	return mem[addr];
}

void write(uint16_t addr, uint8_t val) {
	mem[addr] = val;
}

uint64_t cycleCount;
mos6502 computer(read, write);

uint16_t rangeAddress = 0x0000;

bool memoryEditState = false;

int main(void)
{
	// Copy default program to memory.
	memcpy(mem, prgm, sizeof(prgm));
	dclear(C_BLACK);

	setupHome(computer, mem);

	computer.SetResetP(0b00000100);
    computer.Reset();

	// Main loop
	while (true) {
		key_event_t key = getkey();
		switch (key.key)
		{
		case KEY_EXE:
			computer.Run(1, cycleCount);
			break;
		case KEY_F1: // RUN
			runN();
			break;
		case KEY_F2: // RESET
			rangeAddress = (mem[0xFFFD] << 8) + mem[0xFFFC];
			computer.SetResetP(0b00000100);
    		computer.Reset();
			break;
		case KEY_F3: // INTERRUPT
			break;
		case KEY_F4: // Edit
			break;
		case KEY_F5: // Range
			break;
		case KEY_F6: // Load
			break;
		default:
			break;
		}
		drawMemory(mem, rangeAddress, computer.GetPC());
		drawRegisters(computer);
		dupdate();
	}
	return 1;
}

