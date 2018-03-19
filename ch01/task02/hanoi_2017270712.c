#include<stdio.h>

int TowerofHanoi(int s, int t, int d,int n);

int i = 0;
int main(void){
        int * hanoi;
        int n;

        do{
        printf("input 0<n<20 : ");
        scanf("%d",&n);
        }while(0>n||n>20);


        TowerofHanoi(1,2,3,n);
        printf("Thus, the minimal number of moves is %d\n",i);
        return 0;
}

int TowerofHanoi(int s, int t, int d,int n){
        i++;
        if(n == 1){
                printf("The upmost disk in rod %d is moved to rod %d\n",s,d);
                return 1;
        }
        else if(TowerofHanoi(s,d,t,n-1)){
                printf("The upmost disk in rod %d is moved to rod %d\n",s,d);
                TowerofHanoi(t,s,d,n-1);
                return 1;
        }
        return 0;

};
