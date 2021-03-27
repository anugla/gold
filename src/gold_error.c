#include <curses.h>
#include "gold_error.h"

void handler(int nSignum, siginfo_t* si, void* vcontext) {
	printf("Segmentation Fault! SigNum: %i\n",nSignum);
	ucontext_t* context = (ucontext_t*)vcontext;
	#ifdef __x86_64__
	context->uc_mcontext.gregs[REG_RIP]++;
	#else
	context->uc_mcontext.gregs[REG_EIP]++;
	#endif
	endwin();
	exit(0);
}

void reg_handler() {
	struct sigaction action;
	memset(&action, 0, sizeof(struct sigaction));
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
}
