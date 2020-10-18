#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
char board[251][251];
bool visit[251][251];
int main(){
	int totalV = 0 , totalK = 0;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		getchar();
		for (int j = 0; j < C; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'k') totalK += 1;
			else if (board[i][j] == 'v') totalV += 1;
		}
	}
	memset(visit, false, sizeof(visit));
	//입력정리

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visit[i][j] || board[i][j] == '#') continue;
			
			int v = 0, k = 0;
			queue<pair<int, int>> q;
			
			visit[i][j] = true;
			q.push({ i,j });

			while (!q.empty()) {
				pair<int, int> p = q.front(); q.pop();
				int curX = p.first,
					curY = p.second;

				if (board[curX][curY] == 'v') v += 1;
				else if (board[curX][curY] == 'k') k += 1;

				for (int t = 0; t < 4; t++) {
					int nextX = curX + moveX[t],
						nextY = curY + moveY[t];

					if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
					if (visit[nextX][nextY]) continue;
					if (board[nextX][nextY] == '#') continue;

					visit[nextX][nextY] = true;

					q.push({ nextX,nextY });
				}
			}
			if (k > v) totalV -= v;
			else totalK -= k;
		}
	}
	cout << totalK << " " << totalV;
}
