#ifndef GOLD_GLOADER_H
#define GOLD_GLOADER_H
#include <stdint.h>
#include "gold_gstruct.h"

typedef struct game {
	uint32_t* (*version)();
	void* shared_object;
	char* (*loadLicense)();
	char* (*loadTitle)();
	char* (*loadAbout)();
	char* (*loadName)();
	void (*loadGStruct)(gstruct_t*);
	void (*doFirstFrame)();
	int (*doFrame)(int ch);
	ginfo_t* (*getInfo)();
} game_t;

game_t* gold_loadgame(char* name);
#endif
