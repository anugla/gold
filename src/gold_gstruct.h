#ifndef GOLD_GSTRUCT_H
#define GOLD_GSTRUCT_H

typedef struct gstruct {
	uint32_t version;
	int (*test)();
} gstruct_t;


#endif
