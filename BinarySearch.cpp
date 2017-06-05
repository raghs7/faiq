#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* find minimum number of rotated sorted array */

int BinSearch(int a[], int key, int low, int high) {

	int mid = ( low + high ) / 2;
	printf("key: %d, low: %d, high: %d mid:%d\n", key, low, high, mid);
	if (low > high)
		return -1;


	if (key == a[mid])
		return mid;
	else if (key < a[mid])
		BinSearch(a, key, low, mid - 1);
	else
		BinSearch(a, key, mid + 1, high);
}

int main() {

	int a_sorted[] = {9, 8, 6, 3}; //, 1, 2];
	int a_sorted_rotated[] = {3, 4, 8, 9, 1, 2};

	int n = sizeof(a_sorted) / sizeof(a_sorted[0]);

	printf("minimum %d \n", BinSearch(a_sorted, 6, 0, n));

	return 0;
}
