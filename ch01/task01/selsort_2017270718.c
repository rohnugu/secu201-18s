#include<stdio.h>

int main(){
	int unsorted[10] = {1,5,4,2,7,9,8,10,3,6};
	int i, j, tmp;

	for(i = 0; i < 9;i++){
		for(j = i+1;j<10;j++){
			if(unsorted[i] > unsorted[j]){
				tmp = unsorted[i];
				unsorted[i] = unsorted[j];
				unsorted[j] =  tmp;
			}
		}
	}
	return 0;
}
