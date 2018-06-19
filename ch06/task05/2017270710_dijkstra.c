#include<stdio.h>
#include<string.h>
#include<math.h>
#define IN 100
#define N 5

int dijsktra(int cost[][N], int source, int target)
{
	int dist[N], prev[N], selected[N] = { 0 }, m, d, min, start, i, j;
	char path[N];

	for (i = 1; i< N; i++)
	{
		dist[i] = IN;
		prev[i] = -1;
	}

	start = source;
	selected[start] = 1;
	dist[start] = 0;

	while (selected[target] == 0)
	{
		min = IN;
		m = 0;
		for (i = 1; i< N; i++)
		{
			d = dist[start] + cost[start][i];
			if (d< dist[i] && selected[i] == 0)
			{
				dist[i] = d;
				prev[i] = start;
			}
			if (min>dist[i] && selected[i] == 0)
			{
				min = dist[i];
				m = i;
			}
		}
		start = m;
		selected[start] = 1;
	}
	start = target;
	j = 0;
	while (start != -1)
	{
		path[j++] = start + 65;
		start = prev[start];
	}
	path[j] = '\0';
	strrev(path);
	printf("%s", path);

	return dist[target];
}

int main()
{
	int cost[N][N], i, j, w, ch, num;
	int source, target, x, y;
	printf("The Shortest Path Algorithm \n\n");
	for (i = 1; i< N; i++)
		for (j = 1; j< N; j++)
			cost[i][j] = IN;
	for (x = 1; x< N; x++)
	{
		for (y = x + 1; y< N; y++)
		{
			printf("Enter the weight of the path between nodes %d and %d: ", x, y);
			scanf("%d", &w);
			cost[x][y] = cost[y][x] = w;
		}
		printf("\n");
	}
	printf("\nEnter the source :");
	scanf("%d", &source);
	printf("\nEnter the target :");
	scanf("%d", &target);
	num = dijsktra(cost, source, target);
	printf("\nThe Shortest Path : %d", num);
}
