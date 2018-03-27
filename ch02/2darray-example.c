#include <stdio.h>

void main() {
	int x[3][5] = { {0, 1, 2, 3, 4}, {5, 6, 7, 8, 9}, {10, 11, 12, 13, 14}};

	printf("value of x \t == %p\n", x);
	printf("value x[0] \t == %p\n", x[0]);
	printf("value of x[0][0] == %d\n", x[0][0]);

	printf("addr of x \t == %p\n", &x);
	printf("addr of x[0] \t == %p\n", &x[0]);
	printf("addr of x[0][0] == %p\n", &x[0][0]);

	printf("size of x \t == %lu\n", sizeof(x));
	printf("size of x[0] \t == %lu\n", sizeof(x[0]));
	printf("size of x[0][0] == %lu\n", sizeof(x[0][0]));

	printf("%p %p %p\n", x[0], x[1], x[2]);

	for(int i=0;i<3;i++) {
		for(int j=0;j<5;j++) {
			printf("%p ", &x[i][j]);
		}
		printf("\n");
	}

}
