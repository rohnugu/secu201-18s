#include<stdio.h>
#define swap(u,v) (u ^= v ^= u ^= v)

typedef struct path* pathptr;
typedef struct path {
   int src, dest;
   int lengh;
   pathptr next;
}path;

#define _LENGTH_ 9


/*
#define _LENGTH_ 9
int src[_LENGTH_] = { 0,1,1,2,3,3,4,4,5 };
int dest[_LENGTH_] = { 1,2,6,3,4,6,5,6,0 };
int lengh[_LENGTH_] = { 28,16,14,12,22,18,25,24,10 };
*/

#define _LENGTH_ 16
int src[_LENGTH_]  = {0,0,1,1,1,2,2,3,3,4,5,5,6,6,7,8};
int dest[_LENGTH_] = {1,3,2,3,9,4,5,7,9,6,6,8,8,9,9,9};
//int dest[_LENGTH_] = {B,D,C,D,J,E,F,H,J,G,G,I,I,J,J,J };
int lengh[_LENGTH_]= {4,1,4,4,10,2,1,5,6,2,3,5,3,4,2,3};




int root[_LENGTH_];

int find(int u) {
   if (u == root[u]) return u;
   return root[u] = find(root[u]);
}
void merge(int src, int dest) {
   src = find(src), dest = find(dest);
   if (src > dest)
      swap(src, dest);
   root[src] = dest;
}

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
   pathptr MSThead = NULL;
   pathptr MSTtail = NULL;
   int pathLen = 0;

   for (int i = 0; i < _LENGTH_; i++) {
      if (head == NULL) {
         tail = (path*)malloc(sizeof(path));
         head = tail;
      }
      else {
         tail->next = (path*)malloc(sizeof(path));
         tail = tail->next;
         tail->next = NULL;
      }
      pathLen++;
      tail->src = src[i];
      tail->dest = dest[i];
      tail->lengh = lengh[i];
      printf("src(%d) -> dest(%d) : length(%d)\n", tail->src, tail->dest, tail->lengh);
   }

   printf(" ---------- 1 Round ---------------\n");

   for (int i = 1; i < _LENGTH_; i++)
      root[i] = i;

   for (; pathLen > 0; pathLen--) {
      temp = head;
      int index = 0;
      for (int j = 1; j < pathLen; j++)
         if (fi(temp, index)->lengh > fi(temp, j)->lengh)
            index = j;

      //union find
      int src = find(fi(temp, index)->src), dest = find(fi(temp, index)->dest);
      if (root[src] != root[dest])
         merge(src, dest);
      else {
         printf("pass\n");
         if (index == 0)
            head = head->next;
         else
            fi(head, index - 1)->next = fi(head, index + 1);
         continue;

      }

      // 리스트에 넣기
      if (MSThead == NULL) {
         MSTtail = (pathptr)malloc(sizeof(pathptr));
         MSThead = MSTtail;
         MSTtail = MSThead;
         MSTtail->next = NULL;
      }
      else if (MSThead != NULL) {
         MSTtail->next = (path*)malloc(sizeof(path));
         MSTtail = MSTtail->next;
         MSTtail->next = NULL;
      }

      MSTtail->src = fi(temp, index)->src;
      MSTtail->dest = fi(temp, index)->dest;
      MSTtail->lengh = fi(temp, index)->lengh;

      printf("src(%d) -> dest(%d) : length(%d)\n", MSTtail->src, MSTtail->dest, MSTtail->lengh);

      if (index == 0)
         head = head->next;
      else
         fi(head, index - 1)->next = fi(head, index + 1);

   }

   system("pause");
   return 0;
}
