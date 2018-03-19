#include <stdio.h>

void mov(int from, int to);
void hanoitower(int circlenum, int from, int by, int to);

int main()
{
	int circle;

	printf("input value\n");
	scanf("%d", &circle);	// 3 circles
	hanoitower(circle, 1, 2, 3);
	return 0;
}

void hanoitower(int circlenum, int from, int by, int to) {

	if (circlenum == 1) {
		mov(from, to);
	}
	else {
		hanoitower(circlenum - 1, from, to, by);
		mov(from, to);
		hanoitower(circlenum - 1, by, from, to);
	}
}


void mov(int from, int to) {
	printf("from %d to %d\n", from, to);
}





