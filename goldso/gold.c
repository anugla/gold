
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../src/gold_gstruct.h"

gstruct_t* gs;

extern void goldlib_loadGStruct(gstruct_t* gstruct) {
	gs = gstruct;
}

extern uint32_t goldlib_getVersion() {
	return 1;
}

// licensing info
extern char* goldlib_loadLicense() {
	return "No License";
}

// title for window
extern char* goldlib_loadTitle() {
	return "GOLD Base Game";
}

// inner title
extern char* goldlib_loadName() {
	return "GOLD Base Game";
}

// about (game desc)
extern char* goldlib_loadAbout() {
	return "This is the base game for the GOLD engine";
}

extern ginfo_t* goldlib_getInfo() {
	ginfo_t* info = malloc(sizeof(ginfo_t));
	info->type = TYPE_MISC;
	info->rating = RATING_EVERYONE;
	return info;
}

extern void goldlib_doFirstFrame() {

}

extern int goldlib_doFrame() {
	return 0;
}
