#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MIN(a,b)(a>b?b:a)

using namespace std;
typedef pair<int, int> pii;

int N, M;
int board[10][10];
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};
queue<pii> q;

int main(){
	
	int empty = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			int num; scanf("%d", &num);
			if (num == 0) empty += 1;
			if (num == 2) { q.push({ i,j }); }
			board[i][j] = num;
		}
	}

	int sol = 9999999;
	for (int i = 0; i < N*M -2; i++) {
		if (board[i / M][i % M] != 0 ) continue;

		for (int j = i + 1 ; j < N*M -1; j++) {
			if (board[j / M][j % M] != 0 ) continue;

			for (int k = j + 1; k < N*M; k++) {
				if (board[k / M][k % M] != 0 ) continue;

				int cnt = 0;
				int visit[10][10];
				memset(visit, 0, sizeof(visit));
				queue<pii> t = q;
				
				while (!t.empty()) {
					pii p = t.front(); t.pop();
					int x = p.first, y = p.second;
					if (visit[x][y]) continue;

					visit[x][y] += 1;
					cnt += 1;

					for (int f = 0; f < 4; f++) {
						int nextX = x + moveX[f], nextY = y + moveY[f];
						int next = nextX * M + nextY;

						if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
						if (visit[nextX][nextY] || board[nextX][nextY] != 0 ) continue;
						if (next == i || next == j || next == k) continue;
						
						t.push({ nextX,nextY });
					}
				}

				/*cout << i << " " << j << " " <<  k << " cnt : "<<cnt  << endl;
				for (int l = 0; l < N; l++) {
					for (int r = 0; r < M; r++) {
						cout << visit[l][r] << " ";
					}
					cout << endl;
				}
				cout << endl;*/
				sol = MIN(cnt, sol);
			}
		}
	}
	 
	cout << empty  - sol + q.size() -3;
}
