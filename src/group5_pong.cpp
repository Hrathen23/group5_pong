#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define CON_WIDTH 80  //Console size
#define CON_HIGHT 20

#define CURSOR_SIZE 100  //Size of the hide cursor

void resize_console(uint8_t hight, uint8_t width);  //Subroutine declaration
void gotoxy(uint8_t x, uint8_t y);
void hide_cursor(void);

int main(){

	resize_console(CON_HIGHT, CON_WIDTH);
	hide_cursor();

	while(1==1);
	return 0;

}

void resize_console(uint8_t hight, uint8_t width){  //Subroutine to control the console size

	SMALL_RECT windowSize = {0, 0, (SHORT) (width - 1), (SHORT) (hight -1)};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, &windowSize);
	COORD bufferSize = {SHORT(width), SHORT (hight +1)};
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), bufferSize);

}

void gotoxy(uint8_t x, uint8_t y){  //Subroutine to declare X and Y coordinates

	HANDLE h_console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;

	SetConsoleCursorPosition(h_console, pos);

}

void hide_cursor(void){  //Subroutine to hide the cursor

	CONSOLE_CURSOR_INFO info;

	info.dwSize = CURSOR_SIZE;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

}
