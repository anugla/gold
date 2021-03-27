#ifndef GOLD_GLOADER_H
#define GOLD_GLOADER_H
#include <stdint.h>

typedef struct game {
	uint32_t* (*version)();
	void* shared_object;
	char* (*loadLicense)();
	char* (*loadTitle)();
	char* (*loadAbout)();
	char* (*loadName)();
} game_t;

game_t* gold_loadgame(char* name);
#endif
