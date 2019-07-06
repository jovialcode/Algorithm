#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int R, C;
int moveX[4] = {0,0,-1,1};
int moveY[4] = { -1,1,0,0 };
char board[51][51];

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {

	bool visit[51][51], visit2[51][51];
	priority_queue<pair<int, pii>> pq, flood;
	pii D;
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) {
		getchar();
		for (int j = 0; j < C; j++) {
			scanf("%1c", &board[i][j]);
			if (board[i][j] == 'S') 
				pq.push({ 0, {i,j} });
			else if (board[i][j] == 'D') {
				D.first = i; D.second = j;
			}
			else if(board[i][j] == '*')
				flood.push({ 0, { i,j } });
		}
	}
	memset(visit, false, sizeof(visit));
	memset(visit2, false, sizeof(visit2));
	//입력 정리


	int sol = 0;

	while (!pq.empty()) {
		pair<int, pii> P = pq.top(); pq.pop();
		int cnt = -P.first,
			curX = P.second.first, 
			curY = P.second.second;

		visit2[curX][curY] = true;

		if (curX == D.first && curY == D.second) {
			sol = cnt;
			break;
		}

		while (!flood.empty()) {
			pair<int, pii> p = flood.top(); 
			int floodCnt = -p.first;
			//해당 
			if (cnt != floodCnt) break;

			flood.pop();
			
			int x = p.second.first, y = p.second.second;
			visit[x][y] = true;

			for (int i = 0; i < 4; i++) {
				int nextX = x + moveX[i],
					nextY = y + moveY[i];

				if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
				if (board[nextX][nextY] == 'X'|| board[nextX][nextY] == 'D' || visit[nextX][nextY]) continue;

				visit[nextX][nextY] = true;
				board[nextX][nextY] = '*';

				flood.push({ -(floodCnt + 1),{nextX,nextY} });
			}
		}

		for (int i = 0; i < 4; i++) {

			int nextX = moveX[i] + curX,
				nextY = moveY[i] + curY;

			if (nextX < 0 || nextX >= R || nextY < 0 || nextY >= C) continue;
			if (board[nextX][nextY] == 'X' || board[nextX][nextY] =='*'|| visit2[nextX][nextY]) continue;

			visit2[nextX][nextY] = true;

			pq.push({ -(cnt + 1),{nextX,nextY} });
		}
	}

	//print();
	
	if (!sol) {
		cout << "KAKTUS";
	}
	else {
		cout << sol;
	}

}

