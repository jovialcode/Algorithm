#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<vector<int>> map;
int notebook[202];
int visit[202];

bool dfs(int from) {
	if (visit[from] ) return false;
	
	visit[from] = 1;

	for (int to : map[from]) {
		if(!notebook[to] || dfs(notebook[to])){
			notebook[to] = from;
			return true;
		}
	}
	return false;
}

int main(){
	
	scanf("%d %d", &N, &M);
	map.resize(2 * N + 1);
	memset(notebook, 0, sizeof(notebook));

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		map[from].push_back(N + to);
		map[N + to].push_back(from);
	}
	//입력정리

	int sol = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) sol++;
	}

	cout << sol;
}
