#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include "gold_gloader.h"


int main() {
	int ch;
	int maxlines, maxcols;
	WINDOW *main_window;
	puts("goldLINUX 1.0\n");
	game_t* base = gold_loadgame("games/gold/gold.so");
	printf("gold base version: %08x\n",base->version());
	printf("base license: %s\n",base->loadLicense());
	initscr();
	raw();
	noecho();
	clear();
	maxlines = LINES - 1;
	maxcols = COLS - 1;
	printw(0,0,"%s","F1 to exit");
	refresh();
	main_window = create_newwin(3,10,maxlines/2,maxcols/2);

	while((ch = getch()) != KEY_F(1)) {

	}

	endwin();
	return 0;
}


