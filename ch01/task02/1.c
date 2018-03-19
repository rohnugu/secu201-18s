#include <stdio.h>

void hanoi_tower(int i, char from, char tmp, char to);

int main(void)

{
	int n;
	scanf("%d", &n);
	hanoi_tower(n, 'A', 'B', 'C');//재귀함수

}

void hanoi_tower(int i, char from, char tmp, char to)

{

	if (i == 1)

		printf("원판이동 :1을 %c에서 %c으로 이동!\n", from, to);

	else

	{

		hanoi_tower(i - 1, from, to, tmp);//from, to, tmp로 위치 변경

		printf("원판이동 :%d을 %c에서 %c으로 이동!\n", i, from, to);

		hanoi_tower(i - 1, tmp, from, to);//tmp, from, to로 위치 변경

	}

}


