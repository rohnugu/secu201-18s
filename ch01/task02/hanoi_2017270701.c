#include <stdio.h>

void hanoi(int n, char from, char tmp, char to);

int main() {
	int h;

	printf("input tower's h: ");
	scanf_s("%d", &h);

	hanoi(h, 'a', 'b', 'c');

	return 0;
}

void hanoi(int i, char from, char tmp, char to) {
	static int n = 0;

	if (i == 1) {
		n++;
		printf("1을 %c에서 %c로 옮긴다. 총 %d번 옮겼다.\n", from, to, n);
	}
	else {
		hanoi(i - 1, from, to, tmp);
		n++;
		printf("%d를 %c에서 %c로 옮긴다. 총 %d번 옮겼다.\n", i, from, to, n);
		hanoi(i - 1, tmp, from, to);
	}
}