#include <stdio.h>

int main() {
	int arr[10] = { 5, 10, -1, -4, 7, 9, 2, 3, 20, 15 };
	int arrsize = sizeof(arr) / sizeof(int);
	int min = 0, i, j;

	for (i = 0, j = 1; i < arrsize; i++, j++) {
		int t = j;
		while (t < arrsize) {
			if (arr[min] > arr[t])
				min = t;
			t++;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}

	printf("ARRAY PRINT\n");
	for (int i = 0; i < arrsize; i++)
		printf("%3d", arr[i]);
	printf("\n");

	return 0;
}