#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, mid;
int heavy[101][101], light[101][101];
bool visit[101];

int dfs(int n, bool up) {
	visit[n] = true;

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		if (up && heavy[n][i]) 
			cnt += dfs(i, true) + 1;
		
		if (!up && light[n][i]) 
			cnt += dfs(i, false) + 1;
	}
	return cnt;
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << light[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
	scanf("%d %d", &N, &M);
	memset(heavy, 0, sizeof(heavy));
	memset(light, 0, sizeof(light));
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		light[a][b] = 1;
		heavy[b][a] = 1;
	}
	mid = (N + 1) / 2;
	//입력정리 

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit, false, sizeof(visit));
		int lightCnt = dfs(i, false);

		memset(visit, false, sizeof(visit));
		int heavyCnt = dfs(i, true);

		if (lightCnt >= mid || heavyCnt >= mid) ans += 1;
	}
	cout << ans;
}
