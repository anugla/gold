#include <stdint.h>

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

// about (game desc)
extern char* goldLib_loadAbout() {
	return "This is the base game for the GOLD engine";
}

// name for other things
extern char* loadName() {
	return "GOLD Base Game";
}
