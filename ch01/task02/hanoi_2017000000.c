#include <stdio.h>

int hanoi(int n, int from, int to) {

	int temp = 6 - from - to; // from + to + temp == 6	

	if (n <= 0) {
		printf("Nothing to do\n");
		return 0;
	}

	if (n == 1) {
		printf("The upmost disk in rod %d is moved to rod %d.\n", from, to);
		return 1;
	}

	// n>=2

	int result = 0;

	result += hanoi(n-1, from, temp);
	printf("The upmost disk in rod %d is moved to rod %d.\n", from, to);
	result += 1;
	result += hanoi(n-1, temp, to);

	return result;
}

void main() {
	int n;

	printf("Please input the number of disks: ");
	scanf("%d", &n);
	
	int result = hanoi(n, 1, 3);

	printf("Thus, the minimal number of moves is %d.\n", result);
}
