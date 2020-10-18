#include <iostream>
#include <cstring>
#define MAX(a,b) (a>b?a:b)

using namespace std;

const int INF = -150000001;
const int mx[] = { 1, 0, 0 };
const int my[] = { 0, 1, -1 };

int N, M;
int map[1001][1001];
int dp[1001][1001][3];

int sol(int x, int y,int dir) {
	//기저 사례
	if (x == N-1 && y == M-1) return map[N-1][M-1];

	int & ret = dp[x][y][dir];
	if (ret != INF) return ret;
	for(int d = 0; d<3; d++){
		if (dir * d == 2)
			continue;
		int nx = x + mx[d];
		int ny = y + my[d];
		if (nx >= N || nx<0 ||ny < 0 || ny >= M)
			continue;
		ret = MAX(ret, map[x][y] + sol(nx, ny, d));
	}
	return ret;
}

int main(void) {
	fill(&dp[0][0][0], &dp[1001][0][0], INF);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);
	
	int ans = sol(0, 0,0);
	cout << ans;
	return 0;
}
