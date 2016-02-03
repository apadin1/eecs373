#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sort.h"

/******************** MY CODE **************************/
int compare(int a, int b) {
	    return b-a;
}

int compare_q(int *a, int *b) {
	return *b - *a;
}

/*
Since the compare functions in sort.c are declared as weak, and these
functions are attributed strong (by default) the linker will choose
these functions to use instead of the "weaker" functions in sort.c
*/

/******************** MY CODE **************************/

