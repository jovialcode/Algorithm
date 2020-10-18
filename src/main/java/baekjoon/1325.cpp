#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, sol[10001], visit[10001];
vector<int> adj[10001];

void dfs(int cur) {
	
	visit[cur] = true;

	for (int next : adj[cur]) {
		if (!visit[next]) {
			sol[next] += 1;
			dfs(next);
		}
	}
	return;
}

int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int from, to; scanf("%d%d", &from, &to);
		adj[from].push_back(to);
	}
	memset(sol, -1, sizeof(sol));
	//입력정리

	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, sol[i]);
	}

	for (int i = 1; i <= N; i++) {
		//cout << sol[i] + 1 << " ";
		if (ans == sol[i]) {
			cout << i << " ";
		}
	}
}
