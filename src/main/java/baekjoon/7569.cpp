#include <iostream>
#include <vector>
#include <queue>
#define MIN(a,b)a<b?a:b

using namespace std;
typedef pair<int, int> pii;
int M, N, H;
int board[101 * 101][101];
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};

int main(){

	priority_queue<pair<int,pii>> pq;
	scanf("%d %d %d", &N, &M, &H);

	for (int k = 0; k < H; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				int num; scanf("%d", &num);
				board[i+k*M][j] = num;
				if (num == 1) pq.push({0 ,{i + k * M,j} });
			}
		}
	}// 입력정리

	int sol = 0;
	while (!pq.empty()) {
		pair<int,pii> p = pq.top(); pq.pop();
		int cycle = p.first ,x = p.second.first, y = p.second.second;

		//상하좌우
		for (int i = 0; i < 4; i++) {
			int nextX = x + moveX[i], nextY = y + moveY[i];
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M * H) continue;
			if ( (x/M) != (nextX/M)) continue;
			if (board[nextX][nextY] != 0) continue;

			board[nextX][nextY] = 1;
			pq.push({ (cycle - 1),{nextX,nextY} });

		}
		//아래
		if (x + M < M*H && board[x + M][y] == 0) {
			board[x + M][y] = 1;
			pq.push({(cycle - 1),{x + M, y} });
		}
		//위
		if (x - M >= 0 && board[x - M][y] == 0) {
			board[x - M][y] = 1;
			pq.push({(cycle - 1), {x - M, y} });
		}
		sol = MIN(sol, cycle);
	}

	for (int i = 0; i < M*H; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) {
				cout << "-1"; 
				return 0;
			}
		}
	}

	cout << -sol << endl;

	return 0;
}
