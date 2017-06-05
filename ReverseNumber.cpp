#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void PrintBinDigits(char *start, unsigned int n){
	int mask = 1;
	bool BinDigit;

	printf("n %d\n", n);

	for (int i = n-1; i >= 0; i--) {
		printf(" %.2x: ", start[i]);
		for (int j = 0; j < 8; j++) {
			BinDigit = start[i] & (1 << (7 - j));
			printf("%d ", BinDigit);
		}
	}
	printf("\n");
}


int swapBits(unsigned int n, unsigned int p1, unsigned int p2)
{
    /* Move p1'th to rightmost side */
    unsigned int bit1 =  (n >> p1) & 1;

    /* Move p2'th to rightmost side */
    unsigned int bit2 =  (n >> p2) & 1;

    /* XOR the two bits */
    unsigned int x = (bit1 ^ bit2);

    /* Put the xor bit back to their original positions */
    x = (x << p1) | (x << p2);

    /* XOR 'x' with the original number so that the
       two sets are swapped */
    unsigned int result = n ^ x;

    return result;
}

int main() {
	unsigned int v = 0x55;
	unsigned int r = v, s = sizeof(v) * 8 - 1;

	printf("%x \n", v);
	PrintBinDigits((char*)&v, sizeof(v));

	for (v >>= 1; v; v >>= 1)
	{
		r <<= 1;
		r |= v & 1;
		s--;
	}
	r <<= s; // shift when v's highest bits are zero

	printf("%x \n", r);
	PrintBinDigits((char*)&r, sizeof(r));

	v = r;
	r = v;
	s = sizeof(v) * 8 - 1;

	for (v >>= 1; v; v >>= 1)
	{
		r <<= 1;
		r |= v & 1;
		s--;
	}
	r <<= s; // shift when v's highest bits are zero

	printf("%x \n", r);
	PrintBinDigits((char*)&r, sizeof(r));

	int res =  swapBits(28, 0, 3);
	printf("\nResult = %d \n", res);

	res = 0x55;
	s = sizeof(v) * 8 / 2;

	for (int i = s - 1, j = i + 1; i >= 0; i--, j++) {
		res = swapBits(res, i , j);
	}

	printf("\nResult = %x ", res);
	return 0;
}
