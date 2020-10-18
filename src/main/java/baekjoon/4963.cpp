#include <iostream>
#include <queue>
using namespace std;

const int moveX[9] = {-1,-1,-1,0,0,0,1,1,1};
const int moveY[9] = {-1,0,1,-1,0,1,-1,0,1};

int main(void) {

	int w, h,x,y;
	for (w,h; scanf("%d %d", &w, &h), w != 0 && h != 0; ) {
		int cnt=0;
		int board[51][51], visit[51][51] = { 0, };
		queue<pair<int, int>> q;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &board[i][j]);
		//입력

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] && !visit[i][j]) {
					visit[i][j] = true;
					cnt++;
					q.push(make_pair(i, j));
					while (!q.empty()) {
						x = q.front().first;
						y = q.front().second;
						q.pop();
						for (int next = 0; next < 9; next++) {
							int nx = x + moveX[next];
							int ny = y + moveY[next];
							if (nx < 0 || ny < 0 || nx==h || ny==w) continue;
							if (board[nx][ny] && !visit[nx][ny]) {
								visit[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
		}
		cout << cnt << endl;

	}

	return 0;
}
