#include <iostream>
#include <stdio.h>
#include <string.h>

static int len = 0;

void PermuteUtil(char str[], int count[], char result[], int level){

	if (level == len) {
		printf("level %d, %s\n", level, result);
		return ;
	}

	for (int i = 0; i < len; i++){
		if (count[i] == 0 )
			continue;

		result[level] = str[i];
		count[i]--;
		PermuteUtil(str, count, result, level + 1);
		count[i]++;
	}
}

int main() {

	char str[] = "abc";
	char result[] = "abc";
	int count[] = {1, 1, 1};
	int level = 0;

	len = strlen(str);
	printf("str: %s, len: %d\n", str, len);
	PermuteUtil(str, count, result, level);

	return 0;
}
