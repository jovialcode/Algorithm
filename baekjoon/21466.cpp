#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N;
int board[101][101];
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &board[i][j]);
		}
	}//

	int visit[101][101] = { 0, };
	int area = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			
			if (visit[i][j] || board[i][j] == 0) continue;
			queue<pii> q; 
			q.push({ i,j });
			area += 1;

			while (!q.empty()) {
				pii p = q.front(); q.pop();
				int x = p.first,
					y = p.second;
				if (visit[x][y]) continue;

				visit[x][y] = 1;
				board[x][y] = area;

				for (int k= 0; k < 4; k++) {
					int nextX = x + moveX[k],
						nextY = y + moveY[k];

					if (nextX < 1 || nextX > N || nextY < 1 || nextY > N) continue;
					if (visit[nextX][nextY] || board[nextX][nextY] == 0) continue;

					q.push({nextX, nextY});
				}
			}
		}
	}//MAP 구역 표시

	
	int sol = 100 * 100,
		prev = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			memset(visit, 0, sizeof(visit));
			int area = board[i][j];

			if (visit[i][j] || board[i][j] == 0 || prev == area) continue;
			prev = area;
			
			priority_queue<pair<int, pii>> pq;
			pq.push({ 0,{ i,j }});

			while (!pq.empty()) {
				pair<int,pii> p = pq.top(); pq.pop();
				int cost = -p.first,
					x = p.second.first,
					y = p.second.second;
					
				if (visit[x][y]) continue;
				visit[x][y] = 1;

				if (board[x][y] != 0 && board[x][y] != area) {
					sol = min(sol, -cost);
					break;
				}

				for (int k = 0; k < 4; k++) {
					int nextX = x + moveX[k],
						nextY = y + moveY[k];

					if (nextX < 1 || nextX > N || nextY < 1 || nextY > N || visit[nextX][nextY]) continue;

					if (board[nextX][nextY] == 0) {
						pq.push({ -(cost + 1), {nextX,nextY} });
					}
					else {
						pq.push({ cost, {nextX,nextY} });
					}
				}
			}
		}
	}//다리 길이 구하기

	cout << sol;
	return 0;
}
