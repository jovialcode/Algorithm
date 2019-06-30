#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct ball {
	int cnt;
	int rx, ry, bx, by;
};

int N, M;
int moveX[4] = { 0, 0, -1, 1 };
int moveY[4] = { -1, 1, 0, 0 };
char board[11][11];
bool visit[11][11][11][11];
pair<int, int> g;
queue<ball> q;

void move(int& x, int& y, int way) {
	while (1) {
		x += moveX[way]; y += moveY[way];
		if (board[x][y] == '#') {
			x -= moveX[way]; y -= moveY[way];
			break;
		}
		else if (board[x][y] == 'O')
			break;
	}
}


int sol() {
	int ans = -1;

	while (!q.empty()) {
		ball b = q.front(); q.pop();
		int curCnt = b.cnt;
		

		if (curCnt > 10) break;
		if (b.rx == g.first && b.ry == g.second) {
			ans = curCnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int curRx = b.rx, curRy = b.ry,
				curBx = b.bx, curBy = b.by;

			move(curRx, curRy, i), move(curBx, curBy, i);

			if (curBx == g.first && curBy == g.second) continue;

			if (curRx == curBx && curRy == curBy) {
				switch (i) {
				case 0:
					b.ry < b.by ? curBy++ : curRy++; break;
				case 1:
					b.ry < b.by ? curRy-- : curBy--; break;
				case 2:
					b.rx < b.bx ? curBx++ : curRx++; break;
				case 3:
					b.rx < b.bx ? curRx-- : curBx--; break;
				}
			}

			if (!visit[curRx][curRy][curBx][curBy]) {
				ball next = { curCnt + 1,curRx,curRy,curBx,curBy };
				q.push(next);
				visit[curRx][curRy][curBx][curBy] = true;
			}
		}
	}

	return ans;
}

int main(){
	pair<int, int> r, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		getchar();
		for (int j = 0; j < M; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'R') r = { i, j };
			else if (board[i][j] == 'B') b = { i, j };
			else if (board[i][j] == 'O') g = { i, j };
		}
	}

	q.push({0,r.first, r.second, b.first, b.second});
	visit[r.first][r.second][b.first][b.second] = true;
	//입력정리
	cout << sol();
}
