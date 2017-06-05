#include <stdio.h>

int bulbs(int *A, int n) {
	int state = 0, count = 0, i;

	for (i = 0; i < n; i++){
		if (A[i] == state) {
			count++;
			state = 1 - state;
		}
	}

	return count;
}

int main() {

	int a[] = {1, 0, 0, 1};

	printf("%d\n", bulbs(a, 4));
	return 0;

}
