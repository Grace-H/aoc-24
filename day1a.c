#include <stdio.h>

// Sort an array by placing the sorted indices in another array
int insertion_sort_array(int *array, int *index, int n) {
	for (int i = 0; i < n; i++) {
		index[i] = i;
		int element = array[i];
		int j = i - 1;
		while (j >= 0 && element < array[index[j]]) {
			index[j + 1] = index[j];
			index[j] = i;
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d,", array[index[i]]);
	}
	printf("\n");
	return 0;
}

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

	int indices1[1000];
	int indices2[1000];
	insertion_sort_array(list1, indices1, 1000);
	insertion_sort_array(list2, indices2, 1000);

	int cost = 0;
	for (int i = 0; i < 1000; i++) {
		int diff = list1[indices1[i]] - list2[indices2[i]];
		if (diff < 0) {
			diff *= -1;
		}
		cost += diff;
	}
	printf("%d\n", cost);
	
	return 0;
}
