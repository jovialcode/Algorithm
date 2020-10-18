#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 987654321;

struct block {
	int x, y, cost, dir, state;
};
int moveX[4] = {-1,0,1,0};
int moveY[4] = {0,-1,0,1};

int N, M, dp[51][51][4][4];
char board[51][51];

int main(){

	int cX[2], cY[2], cN = 0;
	block start;

	scanf("%d%d", &N, &M); getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; scanf("%1c", &c);
			if (c == 'S') {
				start = {i,j,0,-1,0};
			}
			if (c == 'C') {
				cX[cN] = i;
				cY[cN++] = j;
			}
			board[i][j] = c;
		}
		getchar();
	}
	//입력정리

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 16; k++)
				dp[i][j][k / 4][k % 4] = INF;
		}
	}

	queue<block> q;
	q.push(start);

	int sol = INF;
	while (!q.empty()) {
		block cur = q.front(); q.pop();

		int x = cur.x,
			y = cur.y,
			cost = cur.cost,
			dir = cur.dir,
			state = cur.state;

		if (state == 3) {
			sol = min(sol, cost);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			if (dir == i) continue;
			int nextX = x + moveX[i],
				nextY = y + moveY[i];

			if (nextX < 0 || nextX == N || nextY < 0 || nextY == M) continue;
			if (board[nextX][nextY] == '#') continue;
			if (state == 1 && cX[0] == nextX && cY[0] == nextY) continue;
			if (state == 2 && cX[1] == nextX && cY[1] == nextY) continue;
			int temp = state;
			temp |= (((cX[1] == nextX && cY[1] == nextY) << 1)| (cX[0] == nextX && cY[0] == nextY));

			if (dp[nextX][nextY][i][temp] <= cost + 1) continue;
;			dp[nextX][nextY][i][temp] = cost + 1;
			q.push({ nextX, nextY, cost + 1, i, temp });
		}
	}

	printf("%d", sol == INF ? -1 : sol);
}
