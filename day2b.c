#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_safe(int* array, int n) {
	int delta = 0;
	int prev_index = 0, current = 0, i = 0;
	if (array[i] == -1) {
		i++;
		prev_index = i;
	}
	for (++i; i < n; i++) {
		if (array[i] == -1) {
			continue;
		}
		current = array[i];
		int diff = array[prev_index] - current;
		if (!delta) {
			delta = diff;
		}
		if (!(delta * diff > 0 && diff != 0 && diff < 4 && diff > -4)) {
			return 0;
		}
		prev_index = i;
	}
	return 1;
}

int main() {
	int safe = 0;

	FILE *f = fopen("input2", "r");
	if (!f) {
		perror("fopen");
		return 1;
	}

	int len = 64;
	char buf[len];
	int nums[10];
	while (!feof(f)) {
		int n = 0;
		fgets(buf, len, f);
		char *token = strtok(buf, " \n");
		while (token) {
			nums[n++] = atoi(token);
			token = strtok(NULL, " \n");
		}
		for (int i = 0; i < n; i++) {
			printf("%d,", nums[i]);
		}

		if (!is_safe(nums, n)) {
			for (int i = 0; i < n; i++) {
				int temp = nums[i];
				nums[i] = -1;
				if (is_safe(nums, n)) {
					printf("dropped successfully");
					safe++;
					break;
				} else {
					nums[i] = temp;
				}
			}
			printf("\n");
		} else {
			printf("safe\n");
			safe++;
		}
	}

	printf("%d\n", safe);
	
	return 0;
}
