#include <stdio.h>
#include "cool.h"
#include "warm.h"

int cool_function(int i, char c, CoolStruct* cs) {
	//printf("i=%d, c=%c, cs={%d, %d}\n", i, c, cs->x + cs->y);
	return warm_function(cs->x, cs->y);
}

int warm_function(int x, int y) {
	return x * y;
}
