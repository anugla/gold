#include "gold_terminal.h"

void settitle(char* title) {
	printf("\033]2;%s\007",title);
}
