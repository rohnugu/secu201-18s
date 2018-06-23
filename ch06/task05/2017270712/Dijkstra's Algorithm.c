#include<stdio.h>
#define swap(u,v) (u ^= v ^= u ^= v)

typedef struct path* pathptr;
typedef struct path {
   int src, dest;
   int lengh;
   pathptr next;
   pathptr prev;
}path;

#define _LENGTH_ 16
int src[_LENGTH_] = {0,0,0,0,1,1,2,2,3,3};
int dest[_LENGTH_] = {1,2,3,4,2,5,3,5,4,5};
int lengh[_LENGTH_] = {5,4,7,9,3,7,8,3,2,4};

pathptr fi(pathptr head, int index) {
   pathptr find = head;

   for (int i = 0; i < index; i++) {
      find = find->next;
      if (find == NULL)
         NULL;

   }
   return find;
}

int main(void) {

   pathptr head = NULL;
   pathptr tail = NULL;
   pathptr temp;

   
   int pathLen = 0;
   printf(" ---------- 1 Round ---------------\n");
   for (int i = 0; i < _LENGTH_; i++) {
      if (head == NULL) {
         tail = (path*)malloc(sizeof(path));
         head = tail;
         tail->prev = NULL;
      }
      else {
         tail->next = (path*)malloc(sizeof(path));
         tail->next->prev = tail;
         tail = tail->next;
         tail->next = NULL;
      }
      pathLen++;
      tail->src = src[i];
      tail->dest = dest[i];
      tail->lengh = lengh[i];
      printf("src(%d) -> dest(%d) : length(%d)\n", tail->src, tail->dest, tail->lengh);
   }

   printf(" ---------- 2 Round ---------------\n");

   int A[_LENGTH_] = { 0 };
   for (int i = 0; i <2; i++) {
      temp = head;
      A[1] = 1;
      int B = 0;
      while (temp != NULL) {
         if (A[temp->src] != 0)
            if (A[temp->dest] > temp->lengh + A[temp->src] || A[temp->dest] == 0) {
               A[temp->dest] = temp->lengh + A[temp->src];
               B = 1;
            }
         if (A[temp->dest] != 0)
            if (A[temp->src] > temp->lengh + A[temp->dest] || A[temp->src] == 0) {
               A[temp->src] = temp->lengh + A[temp->dest];
               B = 1;
            }
         temp = temp->next;
      }
   }
   for (int i = 0; i < _LENGTH_; i++)
      printf("%d, ", A[i] - 1);

   system("pause");
   return 0;
}