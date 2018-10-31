#include <iostream>
#include <queue>
using namespace std;

#define FOR(i,to)for(int i = 0; i<to ; i++)
#define MAX(a,b)(a>b?a:b)

const int moveX[] = { -1,1,0,0 };
const int moveY[] = { 0,0,-1,1 };

int N, M, cnt = 0;
int tomato[1005][1005];

int main(void) {
	int i = 0, j = 0, sol = 1;
	queue<pair<int, int>> q;
	scanf("%d %d", &M, &N);
	FOR(i, N) {
		FOR(j, M) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1 || tomato[i][j] == 0) cnt++;
			if (tomato[i][j] == 1) q.push(make_pair(i, j));
		}
	}
	//입력정리
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop(); cnt--;
		for (int next = 0; next < 4; next++) {
			int nx = x + moveX[next], ny = y + moveY[next];
			if (nx < 0 || ny < 0 || nx == N || ny == M || tomato[nx][ny] == -1) continue;
			if (tomato[nx][ny] == 0) {
				tomato[nx][ny] = tomato[x][y] + 1;
				sol = MAX(sol, tomato[nx][ny]);
				q.push({ nx,ny });
				
			}
		}
	}
	if (cnt == 0)
		cout << sol - 1 << endl;
	else
		cout << "-1"<<endl;
	return 0;
}
