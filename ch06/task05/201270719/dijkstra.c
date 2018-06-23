#include <stdio.h>
#define N 100
#define INF 100000

int cost[N + 1][N + 1];
int visit[N + 1];
int dist[N + 1];
int start, end;
int n, m;
void input()
{
	int i, j;
	int from, to;
	int w;
	printf("input the n start and end : ");
	scanf("%d %d %d", &n, &start, &end);
	printf("? by ? : ");
	scanf("%d", &m);

	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) {
				cost[i][j] = INF;
			}
		}
	}

	for (i = 1; i <= m; i++) 
	{
		printf("input the from to w : ");
		scanf("%d %d %d", &from, &to, &w);
		cost[from][to] = w;
		while (getchar() != "\n");
	}

	for (i = 1; i <= n; i++)
		dist[i] = INF;

}
void dijkstra() {
	int i, j;
	int min;
	int v;
	dist[start] = 0;
	for (i = 0; i <= n; i++) {
		min = INF;
		for (j = 1; j <= n; j++) {
			if (visit[j] ==  0 && min > dist[j]) {
				min = dist[j];
				v = j;
			}
		}
		visit[v] = 1;
		for (j = 1; j <= n; j++) {
			if (dist[j] > dist[v] + cost[v][j]) {
				dist[j] = dist[v] + cost[v][j];
			}
		}
	}
}

int main() {

	input();
	dijkstra();
	printf("최단 경로 : %d\n", dist[end]);
	return 0;
}
