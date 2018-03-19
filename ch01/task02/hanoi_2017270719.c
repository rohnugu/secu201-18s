#include <stdio.h>
//1. 기둥 1에서 n-1개의 원반을 기둥 2로 옮긴다.
//2. 기둥 1에서 1개의 원반을 기둥 3으로 옮긴다.
//3. 기둥 2에서 n-1개의 원반을 기둥 3으로 옮긴다. 
int number = 0;
void change(char from , char  to){
	number++;
	printf("%c막대기에서 %c막대기로 옮겨요! %d번째 옮겼어요\n" , from ,to , number);
	

}
void hanoi_tower(int n, char from , char to , char by){
	if(n == 1 ){
		change(from , to);
		
	}
	else {
		hanoi_tower(n-1 , from , to ,by);
		change(from , to);
		hanoi_tower(n-1 , by , from , to);




	}
	
	

}
int main(){

	printf("hi Hanoi programing\n");
	hanoi_tower(10 , 'A' , 'B' , 'C');
	


}
