#include <stdio.h>

int badbranch_basic(void)
{
	if (0) {
		return 0;
	}
	else {
		return 1;
	}
}

int badbranch_variable(void)
{
	int x = 0;
	if (x) {
		return 0;
	}
	else {
		return 1;
	}
}

int badbranch_uint(void)
{
	unsigned int x = 10;
	if (x >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int badbranch_uint_loop(void)
{
	unsigned int x = 10;
	while(x >= 0) {
		x--;
	}
}

int badbranch_uint_loop_param(unsigned int x)
{
	while(x >= 0) {
		x--;
	}
}
