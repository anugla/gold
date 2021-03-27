#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <string.h>
#include "gold_error.h"
#include "gold_gloader.h"
#include "gold_terminal.h"

int main(int argc, char** argv) {
	int ch;
	int maxlines, maxcols;
	WINDOW *main_window;
	puts("goldLINUX 1.0\n");
	reg_handler();
	printf("argc: %i\n",argc);
	if(argc == 2) {
		printf("arg: %s\n",argv[1]);
		if(strcmp(argv[1],"license") == 0) {
			system("cat ./LICENSE");
			return;
		}
	}
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


