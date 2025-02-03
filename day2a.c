#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int safe = 0;

	FILE *f = fopen("input2", "r");
	if (!f) {
		perror("fopen");
		return 1;
	}

	int len = 64;
	char buf[len];
	while (!feof(f)) {
		fgets(buf, len, f);
		int first = 0, second = 0, delta = 0;
		char *token = strtok(buf, " \n");
		if (token) {
			first = atoi(token);
		} else {
			continue;
		}

		token = strtok(NULL, " \n");
		int safe_so_far = 1;	
		while (token != NULL) {
			second = atoi(token);
			int diff = first - second;
			if (!delta) {
				delta = diff;
			}
			if (!(delta * diff > 0 && diff != 0 && diff < 4 && diff > -4)) {
				safe_so_far = 0;
				break;
			}
			first = second;
			token = strtok(NULL, " ");
		}
		if (safe_so_far) {
			safe++;
		}

	}

	printf("%d\n", safe);
	
	return 0;
}
