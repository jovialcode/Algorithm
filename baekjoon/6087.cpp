#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
int W, H;
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
char board[101][101];
int visit[101][101];
void print() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << visit[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	P c1, c2;
	bool c = false;
	scanf("%d %d", &W, &H);
	for (int i = 0; i < H; i++) {
		getchar();
		for (int j = 0; j < W; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'C') {
				if (c) {
					c2.first = i; c2.second = j;
				}
				else {
					c1.first = i; c1.second = j;
					c = true;
				}
			}
		}
	}
	memset(visit, 999999, sizeof(visit));
	//입력정리

	queue< P > pq;
	pq.push( c1 );

	visit[c1.first][c1.second] = 0;
	while (!pq.empty()) {
		P p = pq.front(); pq.pop();
		int curX = p.first, curY = p.second;
		if (curX == c2.first && curY == c2.second) break;

		for (int i = 0; i < 4; i++) {
			int nextX = curX + moveX[i],
				nextY = curY + moveY[i];

			while (1) {	
				if (nextX < 0 || nextX >= H || nextY < 0 || nextY >= W) break;
				if (visit[nextX][nextY] < visit[curX][curY] +1 || board[nextX][nextY] == '*') break;

				visit[nextX][nextY] = min(visit[nextX][nextY], visit[curX][curY] + 1);
				pq.push({nextX,nextY});

				nextX += moveX[i];
				nextY += moveY[i];
			}
		}
	}
	
	cout << visit[c2.first][c2.second] - 1;
	//print();
}
