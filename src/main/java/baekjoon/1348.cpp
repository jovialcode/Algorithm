#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAXN = 100;
const int INF = 987654321;

int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { 1,-1,0,0 };
int R, C, carSize, parkSize, mid, cost[205][205],matchA[205],matchB[205];
bool visit[205];

char board[51][51];
vector<P> car, park;
vector<int> adj[205];

bool dfs(int cur) {
	visit[cur] = true;
	for (int next : adj[cur]) {
		if (cost[cur][next] <= mid && (matchB[next] == -1 || !visit[matchB[next]] && dfs(matchB[next]))) {
			matchA[cur] = next;
			matchB[next] = cur;
			return true;
		}
	}
	return false;
}



int main(){
	scanf("%d%d", &R, &C); getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'C') {
				car.push_back({ i,j });
			}
			else if (board[i][j] == 'P') {
				park.push_back({ i,j });
			}
		}
		getchar();
	}//입력정리

	carSize = car.size();
	parkSize = park.size();
	
	if (carSize > parkSize) {
		cout << -1 << endl;
		return 0;
	}
	if (carSize == 0) {
		cout << 0 << endl;
		return 0;
	}
	//종료조건

	for (int i = 0; i < carSize; i++) {
		int dist[51][51] = { 0, };
		bool visit[51][51] = { false, };
		int fromX = car[i].first, fromY = car[i].second;
		
		for (int k = 0; k < 51; k++)
			for (int m = 0; m < 51; m++) 
				dist[k][m] = INF;

		queue<P> q;
		q.push({fromX,fromY});
		visit[fromX][fromY] = 1;
		dist[fromX][fromY] = 0;

		while (!q.empty()) {
			P p = q.front(); q.pop();
			int curX = p.first, curY = p.second;

			for (int i = 0; i < 4; i++) {
				int nextX = curX + moveX[i],
					nextY = curY + moveY[i];

				if (nextX < 0 || nextY < 0 || nextX >= R || nextY >= C) continue;
				if (!visit[nextX][nextY] && board[nextX][nextY] != 'X'  ) {
					visit[nextX][nextY] = true;
					dist[nextX][nextY] = dist[curX][curY] + 1;
					q.push({ nextX,nextY });
				}
			}
		}// BFS 

		for (int j = 0; j < parkSize; j++) {
			int parkX = park[j].first, parkY = park[j].second;
			
			if (dist[parkX][parkY] != INF) {
				adj[i].push_back(MAXN + j);
				adj[MAXN + j].push_back(i);
				cost[i][MAXN + j] = dist[parkX][parkY];
				cost[MAXN + j][i] = -dist[parkX][parkY];
			}
		}
	}//그래프 형성

	int match = 0;
	memset(matchA, -1, sizeof(matchA));
	memset(matchB, -1, sizeof(matchB));
	mid = INF;

	for (int i = 0; i < carSize; i++) {
		if (matchA[i] == -1) {
			memset(visit, 0, sizeof(visit));
			if (dfs(i)) match++;
		}
	}
	if (match != carSize) {
		puts("-1");
		return 0;
	}

	int lo = 0, hi = R * C;
	while (lo + 1 < hi) {
		mid = (lo + hi) / 2;
		match = 0;
		memset(matchA, -1, sizeof(matchA));
		memset(matchB, -1, sizeof(matchB));
		for (int i = 0; i < carSize; i++) {
			if (matchA[i] == -1) {
				memset(visit, 0, sizeof(visit));
				if (dfs(i)) match++;
			}
		}
		if (match == carSize) hi = mid;
		else lo = mid;
	}
	cout << hi;
}

