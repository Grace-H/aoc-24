#include <stdio.h>

int main() {
	FILE *f = fopen("input1", "r");
	if (!f) {
		perror("fopen");
		return 1;
	}

	int list1[1000];
	int list2[1000];

	int err = 0;
	int i = 0;
	while (!feof(f)) {
		err = fscanf(f, "%d   %d\n", &list1[i], &list2[i]);
		printf("%d, %d\n", list1[i], list2[i]);
		i++;
	}

	int cost = 0;
	for (int i = 0; i < 1000; i++) {
		int count = 0;
		for (int j = 0; j < 1000; j++) {
			if (list2[j] == list1[i]) {
				count++;
			}
		}
		cost += count * list1[i];
	}
	printf("%d\n", cost);
	
	return 0;
}
