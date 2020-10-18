#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int moveX[8] = { -1,-1,-1,0,0,1,1,1 };
int moveY[8] = { -1,0,1,-1,1,-1,0,1 };

int main(){
	while (1) {
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;

		int ans = 0;
		char board[101][101];
		bool visit[101][101];

		for (int i = 0; i < N; i++) {
			getchar();
			for (int j = 0; j < M; j++)
				scanf("%1c", &board[i][j]);
		}
		memset(visit, false, sizeof(visit));
		//입력정리

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visit[i][j] || board[i][j] == '*')continue;

				visit[i][j] = true;
				ans += 1;

				queue < pair<int, int>> q;
				q.push({ i,j });

				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					int curX = p.first,
						curY = p.second;

					for (int k = 0; k < 8; k++) {
						int nextX = curX + moveX[k],
							nextY = curY + moveY[k];

						if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
						if (visit[nextX][nextY] || board[nextX][nextY] == '*') continue;
						
						visit[nextX][nextY] = true;
						q.push({ nextX,nextY });
					}
				}
			}
		}
		cout << ans << endl;
	}
}
