#include <stdio.h>
//#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LIST 7

int main()
{
	int list[MAX_LIST];

	srand((unsigned)time(NULL));
	
	for(int i=0;i<MAX_LIST;i++) {
		list[i] = rand() % 1000;
	}

	// Selection Sort
	for(int i=0;i<MAX_LIST;i++) {
		for(int j=i+1;j<MAX_LIST;j++) {
			if(list[i] > list[j]) {
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
	}

	for(int i=0;i<MAX_LIST;i++) {
		printf("%d\t", list[i]);
	}
	printf("\n");

	int left = 0;
	int right = MAX_LIST-1;
	int searchnum = list[2];
	int findindex = -1;
	
	while(left<=right) {
		int middle = (left + right) / 2;
		if(searchnum < list[middle])
			right = middle -1;
		else if (searchnum == list[middle]) {
			findindex = middle;
			break;
		} else left = middle + 1;
	}

	if (findindex < 0) {
		printf("tried to find %d but not appeared.\n", searchnum);
		printf("program stopped between %d and %d\n", left, right);
	} else {
		printf("tried to find %d and its index is %d.\n", searchnum, findindex);
	}

	return 0;
}
