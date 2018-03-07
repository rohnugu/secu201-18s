#include<stdio.h>

int main(){
	int x[10]={10, 3, 1, 46, 55, -35, 365, 23, 48, 8}, i=0, tmp=0;
	int j=0;
	for(i=0;i<10;i++){
		for(j=i+1;j<10;j++){
			if(x[i]>x[j]){
			tmp=x[i];
			x[i]=x[j];
			x[j]=tmp;
			}
		}
	}
	for(i=0;i<10;i++){
		printf("%d ", x[i]);
	}
	printf("\n");
	


}
