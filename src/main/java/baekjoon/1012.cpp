#include <iostream>
#include <queue>
using namespace std;

const int moveX[] = { 0,0,-1,1 };
const int moveY[] = { 1,-1,0,0 };

int main(void) {
	int T; scanf("%d", &T);

	while (T--) {
		bool board[51][51] = { false, };
		bool visit[51][51] = { false, };
		int sol = 0;
		int M, N, K; scanf("%d %d %d", &M, &N, &K);
		while (K--) {
			int x, y; scanf("%d %d", &x, &y);
			board[x][y] = true;
		}
		for (int i = 0; i < M; i++)
			for(int j = 0; j<N; j++)
				if (board[i][j] && !visit[i][j]) {
					sol++;
					queue<pair<int, int>> q;
					q.push({ i,j });
					visit[i][j] = true;
					while (!q.empty()) {
						int x = q.front().first;
						int y = q.front().second;
						q.pop();
						for (int t = 0; t < 4; t++) {
							int nx = x + moveX[t], ny = y + moveY[t];
							if (nx < 0 || ny < 0 || nx == M || ny == N || visit[nx][ny]) continue;
							if (board[nx][ny]) {
								q.push({ nx,ny });
								visit[nx][ny] = true;
							}
						}
					}
				}
		cout << sol << endl;
	}
	return 0;
}