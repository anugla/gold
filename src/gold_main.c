#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include "gold_gloader.h"
#include "gold_terminal.h"

int main() {
	int ch;
	int maxlines, maxcols;
	WINDOW *main_window;
	puts("goldLINUX 1.0\n");
	game_t* base = gold_loadgame("games/gold/gold.so");
	printf("gold base version: %08x\n",base->version());
	printf("base license: %s\n",base->loadLicense());
	settitle(base->loadTitle());
	initscr();
	cbreak();
	noecho();
	clear();
	maxlines = LINES - 1;
	maxcols = COLS - 1;
	//printw bringing up SIGSEV for some raisin.
	//printw(0,0,"%s -- GOLD", base->loadName());
	//printw(1,1,"%s","F1 to exit");
	refresh();

	while((ch = getch()) != KEY_F(1)) {
		
	}

	endwin();
	puts("Goodbye!");
	return 0;
}


