#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

int moveX[4] = { -1,0,1,0 };
int moveY[4] = { 0,1,0,-1 };

int N, M;
int board[51][51], visit[51][51];

bool areaCheck(int x, int y) {
	if( x < 0 || x >= N || y < 0 || y >= M) return false;
	else return true;
}

int turnDir(int d) {
	if (d == 0) {
		return 3;
	}
	else if (d == 1) {
		return 0;
	}
	else if (d == 2) {
		return 1;
	}
	else {
		return 2;
	}
}

int main(){
	scanf("%d%d", &N, &M);
	pair<int, P> start;
	scanf("%d%d%d", &start.second.first, &start.second.second, &start.first);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			scanf("%d", &board[i][j]);
	//입력정리

	queue<pair<int, P>> q;
	q.push(start);
	visit[start.second.first][start.second.second] = 1;

	int sol = 1;
	while (!q.empty()) {
		pair<int, P> cur = q.front(); q.pop();
		int dir = cur.first,
			x = cur.second.first,
			y = cur.second.second;

		int nextDir = dir,
			nextX = 0,
			nextY = 0;
		bool noWhere = true;

		for(int i = 0; i < 4; i++){
			nextDir = turnDir(nextDir);
			nextX = x + moveX[nextDir],
			nextY = y + moveY[nextDir];

			if (areaCheck(nextX,nextY) &&!visit[nextX][nextY] && board[nextX][nextY] == 0) {
				visit[nextX][nextY] = 1;
				sol += 1;
				q.push({ nextDir,{nextX,nextY} });
				noWhere = false;
				break;
			}
		}

		int revDir = (nextDir > 1 ? nextDir - 2 : nextDir + 2);
		nextX = x + moveX[revDir], nextY = y + moveY[revDir];

		if (noWhere && areaCheck(nextX,nextY) && board[nextX][nextY] == 0) {
			q.push({ dir,{ nextX, nextY}});
		}
	}
	cout << sol;
}
