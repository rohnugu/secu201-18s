#include <stdio.h>
int main(){
	int a[10]={6,5,3,1,2,3,4,7,8,10};
	int i,j;
	int temp;
	printf("unsorted array!\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("sorted array!\n");
	for(i=0;i<10;i++){
	for(j=0;j<10;j++){
	if(a[i]<a[j]){
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
}
}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
}
