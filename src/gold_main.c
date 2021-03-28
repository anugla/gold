#include <stdio.h>
#ifndef NOCURSES
#include <curses.h>
#endif
#include <stdlib.h>
#include <string.h>
#include "gold_error.h"
#include "gold_gloader.h"
#include "gold_terminal.h"

int main(int argc, char** argv) {
	int ch;
	int maxlines, maxcols;
	#ifndef NOCURSES
	WINDOW *main_window;
	#endif
	puts("goldLINUX 1.0\n");
	reg_handler();
	printf("argc: %i\n",argc);
	if(argc == 2) {
		printf("arg: %s\n",argv[1]);
		if(strcmp(argv[1],"license") == 0) {
			system("cat ./LICENSE");
			return 0;
		}
	}
	game_t* base = gold_loadgame("games/gold/gold.so");
	gstruct_t* gstruct = malloc(sizeof(gstruct_t));
	printf("gold base version: %08x\n",base->version());
	printf("base license: %s\n",base->loadLicense());
	settitle(base->loadTitle());
	base->loadGStruct(gstruct);

	#ifndef NOCURSES
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
	#endif

	ginfo_t* info = base->getInfo();
	int s = 0;
	int quitting = 0;
	while((ch = getch()) != KEY_F(1)) {
		s = base->doFrame(ch);
		switch(s) {
			case 1: // exit gracefully
				quitting = 1;
				break;
			case 2: // issue
				quitting = 1;
				break;
			default:
				break;
		}
		if(quitting == 1) {
			if(s != 1) {
				printf("Oops! Quitting with code %i",s);
			}
			break;
		}
	}

	endwin();
	puts("Goodbye!");
	return 0;
}


