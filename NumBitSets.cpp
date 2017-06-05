#include <stdio.h>

int numBitSets(unsigned x) {
	int count = 0;
	while(x) {
		x = x & (x - 1);
		count++;
	}

	return count;

}
int main () {

	unsigned int n = 2;

	scanf("%u", &n);

	printf("n: %u\n", n);

	printf("%d\n", numBitSets(n));

	return 0;
}
