#ifndef GOLD_GSTRUCT_H
#define GOLD_GSTRUCT_H
#include <stdint.h>

typedef struct gstruct {
	uint32_t version;
	int (*test)();
} gstruct_t;

enum gtype {
	TYPE_ADVENTURE, // console only
	TYPE_UI, // setup basic ui environment
	TYPE_MISC, // let program manage itself
};

enum grating {
	RATING_CHILD, // children (0-8)
	RATING_EVERYONE, // everyone (9-max age possible...)
	RATING_TEEN, // (13-21)
	RATING_ADULT, // (22-max age possible...)
	RATING_MATURE, // RATING_ADULT but even grosser
};

typedef struct ginfo {
	enum gtype type;
	enum grating rating;
} ginfo_t;

#endif
