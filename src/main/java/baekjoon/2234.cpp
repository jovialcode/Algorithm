#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int board[51][51];
int moveX[4] = { 0,0,-1,1 };
int moveY[4] = { -1,1,0,0 };
int moveOkay[4][8] = {
	{4,5,6,7,12,13,14,15},
	{1,3,5,7,9,11,13,15},
	{8,9,10,11,12,13,14,15},
	{2,3,6,7,10,11,14,15}
};

int main() {
	int roomCnt = 0, maxRoomSize = 0, sol = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++) 
			scanf("%d", &board[i][j]);
	//입력정리

	int visit[51][51];
	vector<int> room(2501,0);
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != 0) continue;
			int roomSize = 1;

			roomCnt += 1; //룸 갯수 세기
			visit[i][j] = roomCnt;
			queue<pair<int, int>> q;
			q.push({ i,j });

			while (!q.empty()) {
				pair<int,int> p = q.front();
				q.pop();
				
				int curX = p.first;
				int curY = p.second;

				for (int k = 0; k < 4; k++) {
					int nextX = curX + moveX[k];
					int nextY = curY + moveY[k];
					int okay = true;

					if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
					if(visit[nextX][nextY] > 0) continue;
					for (int t = 0; t < 8; t++) 
						if (board[nextX][nextY] == moveOkay[k][t]) okay = false;
					if (!okay) continue;

					visit[nextX][nextY] = roomCnt;
					roomSize += 1;

					q.push({ nextX,nextY });
				}
			}
			room[roomCnt] = roomSize;
			maxRoomSize = max(maxRoomSize, roomSize);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int curRoom = visit[i][j];

			for (int k = 0; k < 4; k++) {
				int nextX = i + moveX[k];
				int nextY = j + moveY[k];
				if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N) continue;
				int nextRoom = visit[nextX][nextY];
				if (curRoom != nextRoom) {
					sol = max(room[curRoom] + room[nextRoom], sol);
				}
			}
		}
	}

	cout << roomCnt << endl << maxRoomSize<<endl<<sol<<endl;
}
