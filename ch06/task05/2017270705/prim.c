#include <stdio.h>
#include <stdlib.h>

#define Inf 10000
#define MAX_VERTICES 7

typedef struct node *nodePointer;

typedef struct node {
	int Vertex;
	int nextVertex;
	int dist;
	nodePointer nextLink;		// next address
}node;

// p.309
int cost[][MAX_VERTICES] = {
	0,		28,		Inf,	Inf,	Inf,	10,		Inf,
	28,		0,		16,		Inf,	Inf,	Inf,	14,	
	Inf,	16,		0,		12,		Inf,	Inf,	Inf,
	Inf,	Inf,	12,		0,		22,		Inf,	18,	
	Inf,	Inf,	Inf,	22,		0,		25,		24,	
	10,		Inf,	Inf,	Inf,	25,		0,		Inf,
	Inf,	14,		Inf,	18,		24,		Inf,	0	
};

void prim(int cost[][MAX_VERTICES], nodePointer *start_ptr, int startVertex);
void Free(nodePointer ptr);

int main()
{
	nodePointer start_ptr;
	nodePointer ptr;
	int startVertex = 0;
	int mincost = 0;

	printf("prim algorithm\n\n");
	prim(cost, &start_ptr, startVertex);
	ptr = start_ptr;
	for (int i = 0; i < MAX_VERTICES - 1; i++) {
		printf("move vertex : (%d) -- (%d)\t\tcost : (%d)\n", ptr->Vertex, ptr->nextVertex, ptr->dist);
		mincost += ptr->dist;
		ptr = ptr->nextLink;
	}
	printf("---------------------------------------------------\n");
	printf("mincost : (%d)\n\n\n", mincost);
	Free(start_ptr);
	return 0;
}

void Free(nodePointer ptr) {
	nodePointer temp;
	while ((ptr->nextLink)) {
		temp = ptr->nextLink;
		free(ptr);
		ptr = temp;
	}
	free(ptr);
}

void prim(int cost[][MAX_VERTICES], nodePointer *start_ptr, int startVertex) {
	int distance[MAX_VERTICES];
	int min = Inf;
	int cnt = 0, temp_idx = 0, sv_idx = 0;

	nodePointer temp_link = NULL;
	nodePointer ptr;

	do {
		for (int i = startVertex, j = 0; j < MAX_VERTICES; j++) {
			distance[j] = cost[i][j];
		}
		for (int i = 0; i < MAX_VERTICES; i++) {

			if (distance[i] < min && distance[i] != 0) {
				sv_idx = i;
				if (temp_link)
					if (temp_link->Vertex == sv_idx) {
						sv_idx = temp_idx;
						continue;
					}
				temp_idx = sv_idx;
				min = distance[i];
			}
		}
		min = Inf;
		ptr = (nodePointer)malloc(sizeof(node));
		ptr->Vertex = startVertex;
		ptr->nextVertex = sv_idx;
		ptr->dist = distance[sv_idx];
		ptr->nextLink = NULL;


		if (cnt != 0) {
			temp_link->nextLink = ptr;
			temp_link = ptr;
			startVertex = ptr->nextVertex;
			cnt++;
			continue;
		}
		(*start_ptr) = ptr;
		temp_link = ptr;
		startVertex = ptr->nextVertex;
		cnt++;
	} while (cnt < MAX_VERTICES - 1);
}