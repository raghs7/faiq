#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void* malloc_align(size_t size, int align) {
	int sizeof_p = sizeof(int *);
	printf("sizeof int* %d, size_t %d size_t * %x\n", sizeof_p, sizeof(size_t), sizeof(size_t*));

	void *p1, *p2;
	size_t addr;
	if ((p1 = malloc(size + align + sizeof_p)) == NULL) {
		perror("\n");
		return NULL;
	}

	addr = (size_t)p1 + align + sizeof_p;

	p2 = (void*)(addr - addr % align);

	*((size_t*)p2 - 1) = (size_t)p1;

	printf("p1: %x, p2:%x, *p2-1: %x\n", p1, p2, *((size_t*)p2 - 1));

	return p2;

}

void free_align(void *p){
	printf("p: %x\n", (size_t)p);
	void *p1 = (void*)(((size_t*)p - 1));
	printf("p1: %x *p1 %x\n", (size_t)p1, *(size_t*)p1);

	free((void*)(*(size_t*)p1));
}

int main() {
	int *x = (int*) malloc_align(200, 8);

	printf("x: %x\n", x);

	free_align(x);

	return 0;
}
