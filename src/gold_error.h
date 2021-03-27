#ifndef GOLD_ERROR_H
#define GOLD_ERROR_H

#include <stdio.h>
#define __USE_GNU
#include <stdlib.h>
#include <signal.h>
#include <execinfo.h>

void handler(int nSignum, siginfo_t* si, void* vcontext);

void reg_handler();

#endif
