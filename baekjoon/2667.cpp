#include <cstdio>
#include <queue>
#include <algorithm>

#define Y (y+dy[i])
#define X (x+dx[i])
using namespace std;

int graph[30][30];
int check[30][30];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };
int cnt_arr[300];
void bfs(int y, int x, int cnt) {
	queue<pair<int, int> > q;
	check[y][x] = 1;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		cnt_arr[cnt] ++;
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (graph[Y][X] && !check[Y][X]) {
				check[Y][X] = 1;
				q.push(make_pair(Y, X));
			}
		}
	}
}
int main() {
	int n,i, j, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (graph[i][j] && !check[i][j]) {
				bfs(i, j, cnt++);
			}
		}
	}
	printf("%d\n", cnt);
	sort(cnt_arr, cnt_arr + cnt);
	for (i = 0; i < cnt; i++) {
		printf("%d\n", cnt_arr[i]);
	}
	return 0;
}
