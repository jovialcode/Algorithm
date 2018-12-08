#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

const int INF = 987654321;
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
int R, C, dist[1001][1001];
char board[1001][1001];

int imp() {
	int ans = INF;
	for (int i = 1; i <= R; i++) {
		ans = min(ans, min(dist[i][1], dist[i][C]));

	}//가로
	for (int i = 1; i <= C; i++) {
		ans = min(ans, min(dist[1][i], dist[R][i]));
	}//세로
	return ans;
}

int main(){
	scanf("%d%d", &R, &C); getchar();

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			dist[i][j] = INF;
		}
	}

	queue<P> start;
	priority_queue<pair<int,P>> fire;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'J') {
				dist[i][j] = 1;
				start.push({ i,j });
			}
			else if (board[i][j] == 'F') {
				dist[i][j] = INF;
				fire.push({ 0,{ i,j } });
			}
		}
		getchar();
	}//입력정리

	int sol = 0;
	while (!start.empty()) {
		
		int fSize = fire.size();
		for(int t = 0; t<fSize; t++){
			pair<int,P> curF = fire.top(); fire.pop();
			int step = -curF.first, fx = curF.second.first, fy = curF.second.second;

			for (int i = 0; i < 4; i++) {
				int nx = fx + moveX[i],
					ny = fy + moveY[i];

				if (nx < 1 || ny < 1 || nx > R || ny > C || board[nx][ny] == '#') continue;
				if (board[nx][ny] == '.') {
					board[nx][ny] = 'F';
					fire.push({ -(step +1), { nx,ny } });
				}
			}
		}//불의 이동

		int jSize = start.size();
		for (int t = 0; t < jSize; t++) {
			P curJ = start.front(); start.pop();
			int jx = curJ.first, jy = curJ.second;

			if (jx == 1 || jx == R || jy == 1 || jy == C) {
				cout << dist[jx][jy];
				return 0;
			}

			for (int i = 0; i < 4; i++) {
				int nx = jx + moveX[i],
					ny = jy + moveY[i];

				if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
				if (board[nx][ny] == '.' && dist[nx][ny] > dist[jx][jy] + 1) {
					dist[nx][ny] = dist[jx][jy] + 1;
					start.push({ nx,ny });
				}
			}
		}//지훈이 이동
	}

	cout << "IMPOSSIBLE";
}
