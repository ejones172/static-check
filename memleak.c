#include <stdlib.h>

void* global_mem;

void* memleak_malloc(void)
{
	return malloc(42);
}

void memleak_free(void* p)
{
	free(p);
}

void memleak_basic_leak(void)
{
	// Most basic case, just allocate memory and not free it
	void* p = malloc(42);
}

void memleak_basic_leak2(void)
{
	// allocate memory through an indirect function call
	void* p = memleak_malloc();
}

void memleak_double_free(void)
{
	// Allocate and then double free
	void* p = malloc(42);
	free(p);
	free(p);
}

void memleak_double_free2(void)
{
	// double free through function call
	void* p = memleak_malloc();
	memleak_free(p);
	memleak_free(p);
}

void memleak_double_malloc_single_free(void)
{
        void* p = malloc(42);
        p = malloc(42);
        free(p);
}

void memleak_double_malloc_single_free2(void)
{
	void* p = memleak_malloc();
	p = memleak_malloc();
	memleak_free(p);
}

void memleak_global_malloc(void)
{
	// Allocate memory and store in global variable. Possible leak
	global_mem = malloc(42);
}

void memleak_global_free(void)
{
	// Free memory stored in global. Possible double free
	free(global_mem);
}

void memleak_global_malloc_leak(void)
{
	global_mem = malloc(42);
	global_mem = malloc(42);
}


void memleak_global_malloc_leak2(void)
{
	memleak_global_malloc();
	memleak_global_malloc();
	memleak_global_free();
}

void memleak_global_double_free(void)
{
	memleak_global_malloc();
	memleak_global_free();
	memleak_global_free();
}


