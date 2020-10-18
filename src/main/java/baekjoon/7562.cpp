#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int moveX[] = { -1,-2,-2,-1,1,2,2,1 };
int moveY[] = { -2,-1,1,2,-2,-1,1,2 };

int main(void) {
	int T; scanf("%d", &T);

	while (T--) {
		int board[302][302] = { 0, };
		int N, fromX, fromY, toX, toY;
		scanf("%d %d %d %d %d", &N, &fromX, &fromY, &toX, &toY);

		if (fromX == toX && fromY == toY) {
			printf("0\n");
			continue;
		}

		for (int i = 0; i <= 300; i++)
			for (int j = 0; j <= 300; j++)
				board[i][j] = INT_MAX;

		//입력정리
		queue<pair<int, int>> pq;
		pq.push({ fromX,fromY });
		board[fromX][fromY] = 0;

		while (!pq.empty()) {
			int nowX = pq.front().first;
			int nowY = pq.front().second;
			
			pq.pop();
			for (int next = 0; next < 8; next++) {
				int nextX = nowX + moveX[next];
				int nextY = nowY + moveY[next];
				if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
				
				if (board[nextX][nextY] > board[nowX][nowY] + 1) {
					board[nextX][nextY] = board[nowX][nowY] + 1;
					pq.push({ nextX,nextY });
				}
			}
		}
		printf("%d\n", board[toX][toY]);
	}
	return 0;
}
