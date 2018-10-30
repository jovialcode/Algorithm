#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int INF = 987654321;
typedef pair<int, int> P;
bool visit[7][13];
int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
queue<P> ans;
string board[7];

void bfs(int x, int y) {

	queue<P> q,temp;
	q.push({ x,y });

	char c = board[x][y];
	while (!q.empty()) {
		P p = q.front(); q.pop();
		int hereX = p.first,
			hereY = p.second;

		if (visit[hereX][hereY]) continue;
		visit[hereX][hereY] = 1;

		temp.push({ hereX,hereY });

		for (int i = 0; i < 4; i++) {
			int nextX = hereX + moveX[i],
				nextY = hereY + moveY[i];

			if (nextX < 0 || nextX > 5 || nextY < 0 || nextY > 11) continue;
			if (visit[nextX][nextY] || board[nextX][nextY] != c ) continue;
				q.push({ nextX,nextY });
		}
	}
	if (temp.size() >= 4) {
		while (!temp.empty()) {
			ans.push(temp.front());
			temp.pop();
		}
	}

	return ;
	
}

int main(){
	for (int i = 0; i < 6; i++) {
		board[i] = "";
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			char c; scanf("%1c", &c);
			board[j].push_back(c);
		}
		getchar();
	}

	for (auto &v : board) {
		reverse(v.begin(), v.end());
	}
	//입력정리
	int sol = 0;
	while (1) {
		memset(visit, 0, sizeof(visit));

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < board[i].size(); j++) {
				char c = board[i][j];
				if (c == '.' || visit[i][j] ) continue;
				bfs(i, j);
			}
		}

		if (ans.empty()) break;
		else { 
			while (!ans.empty()) {
				P p = ans.front(); ans.pop();
				int hereX = p.first,
					hereY = p.second;

				board[hereX][hereY] = '.';
			}

			for (int i = 0; i < 6; i++) {
				string temp1 = "";
				string temp2 = "";

				for (int j = 0; j < board[i].size(); j++) {
					if (board[i][j] != '.') {
						temp1 += board[i][j];
					}
					else {
						temp2 += board[i][j];
					}
				}
				board[i] = temp1 + temp2;
			}

			sol += 1; 
		}
	}

	cout << sol;
	
}
