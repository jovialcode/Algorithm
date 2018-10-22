#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
char board[51][51];
int h[51][51], v[51][51];
int aMatch[2501],bMatch[2501], visit[2501];
vector<vector<int>> adj(2501);

bool dfs(int start) {
	if (visit[start]) return false;
	visit[start] = true;

	for (int next : adj[start]) {
		if (bMatch[next] == -1 || dfs(bMatch[next])) { 
			bMatch[next] = start;
			aMatch[start] = next;
			return true; 
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &N, &M);
	int aOrder = 1, bOrder = 1;
	getchar();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1c", &board[i][j]);
		}
		getchar();
	}// 입력정리
	
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		if (board[i][1] == '.') cnt += 1;

		for (int j = 1; j <= M; j++) {
			char cur = board[i][j];

			if (cur == '*') { 
				h[i][j] = aOrder;
				cnt = 0;
			}
			else {
				if (cnt > 0) cnt += 1;
				else { 
					aOrder += 1;
					cnt += 1; 
				}
			}
		}
		if (cnt == 0 && i != N) aOrder += 1;
	}
	// 가로

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		if (board[1][i] == '.') cnt += 1;

		for (int j = 1; j <= M; j++) {
			char cur = board[j][i];

			if (cur == '*') {
				v[j][i] = bOrder;
				cnt = 0;
			}
			else {
				if (cnt > 0) cnt += 1;
				else {
					bOrder += 1;
					cnt += 1;
				}
			}
		}
		if (cnt == 0 && i != N) bOrder += 1;
	}//세로

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int ah = h[i][j], bv = v[i][j];
			adj[ah].push_back(bv);
		}
	}//간선 만들기
	 
	memset(aMatch, -1, sizeof(aMatch));
	memset(bMatch, -1, sizeof(bMatch));

	int sol = 0;
	for (int i = 1; i <= aOrder; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) sol++;
	}
	cout << sol;
}
