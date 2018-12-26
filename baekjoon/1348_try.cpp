#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int MAXN = 100;
const int S = 203, T = 204;
const int INF = 987654321;

int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { 1,-1,0,0 };
int R, C , flow[205][205],  cost[205][205];
char board[51][51];
vector<P> car, park;
vector<int> adj[205];

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

	int carSize = car.size();
	int parkSize = park.size();
	
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
		}// BFS Parking lot 도달여부

		for (int j = 0; j < parkSize; j++) {
			int parkX = park[j].first, parkY = park[j].second;
			
			if (dist[parkX][parkY] != INF) {
				adj[i].push_back(MAXN + j);
				adj[MAXN + j].push_back(i);
				flow[i][MAXN + j] = 1;
				cost[i][MAXN + j] = dist[parkX][parkY];
				cost[MAXN + j][i] = -dist[parkX][parkY];
			}
		}//그래프 형성
	}

	for (int i = 0; i < carSize; i++) {
		adj[S].push_back(i);
		adj[i].push_back(S);
		flow[S][i] = 1;
		cost[i][S] = INF;
	}

	for (int i = 0; i < parkSize; i++) {
		adj[T].push_back(i + MAXN);
		adj[i + MAXN].push_back(T);
		flow[i + MAXN][T] = 1;
		cost[T][i + MAXN] = INF;
	}

	int cnt = 0, sol = 0;
	while (1) {
		int prev[205], dist[205];
		bool inQ[205] = { 0, };

		fill(dist, dist + 205, INF);
		fill(prev, prev + 205, -1);

		queue<int> q;
		q.push(S);

		inQ[S] = true;
		dist[S] = 0;

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			inQ[cur] = false;

			for (int next : adj[cur]) {
				if (flow[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
					dist[next] = dist[cur] + cost[cur][next];
					prev[next] = cur;

					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
					}
				}
			}
		}

		if (prev[T] == -1) {
			break;
		}

		cnt += 1;
		for (int start = T; start != S; start = prev[start]) {
			flow[start][prev[start]] += 1;
			flow[prev[start]][start] -= 1;
			sol = max(sol, cost[prev[start]][start]);	
		}
	}

	if (cnt == carSize) {
		cout << sol;
	}
	else {
		cout << -1;
	}
}

