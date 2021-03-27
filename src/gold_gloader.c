#include <stdlib.h>
#include <dlfcn.h>
#include "gold_gloader.h"

game_t* gold_loadgame(char* name) {
	game_t* loaded_game = (game_t*)malloc(sizeof(game_t));
	loaded_game->shared_object = dlopen(name,RTLD_NOW);
	loaded_game->version = dlsym(loaded_game->shared_object, "goldlib_getVersion");
	loaded_game->loadLicense = dlsym(loaded_game->shared_object, "goldlib_loadLicense");
	loaded_game->loadTitle = dlsym(loaded_game->shared_object, "goldlib_loadTitle");
	loaded_game->loadAbout = dlsym(loaded_game->shared_object, "goldlib_loadAbout");
	loaded_game->loadName = dlsym(loaded_game->shared_object, "goldlib_loadName");
	loaded_game->loadGStruct = dlsym(loaded_game->shared_object, "goldLib_loadGStruct");
}
