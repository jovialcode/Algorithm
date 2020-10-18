#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
char board[51][51];
int h[51][51], v[51][51];
int match[2501], visit[2501];
vector<vector<int>> adj(2501);

bool dfs(int start) {
	if (visit[start]) return false;
	visit[start] = true;

	for (int next : adj[start]) {
		if (match[next] == -1 || dfs(match[next])) { 
			match[next] = start;
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
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == '.') continue;
			if (j == 1 || h[i][j - 1] == 0)
				h[i][j] = aOrder++;
			else
				h[i][j] = h[i][j - 1];
		}
	}//가로

	for (int j = 1; j <= M; j++) {
		for (int i = 1; i <= N; i++) {
			if (board[i][j] == '.') continue;
			if (i == 1 || v[i - 1][j] == 0)
				v[i][j] = bOrder++;
			else
				v[i][j] = v[i - 1][j];
		}
	}//
	

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (board[i][j] == '.') continue;
			int ah = h[i][j], bv = v[i][j];
			adj[ah].push_back(bv);
		}
	}//간선 만들기
	 
	memset(match, -1, sizeof(match));

	int sol = 0;
	for (int i = 1; i <= aOrder; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) sol++;
	}
	cout << sol;
}
