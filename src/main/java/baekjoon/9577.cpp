#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, maxTo;
int match[302], visit[302];
vector<vector<int>> adj;

bool dfs(int start) {
	if (visit[start]) return false;
	visit[start] = 1;

	for (int next : adj[start]) {
		if (match[next] == -1 || dfs(match[next])) {
			match[next] = start;
			return true;
		}
	}
	return false;
}
int main(){
	int T; scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N, &M);

		memset(match, -1, sizeof(match));
		adj.clear();
		adj.resize(302);
		maxTo = 0;

		for (int i = 1; i <= M; i++) {
			int T1, T2, A; scanf("%d %d %d", &T1, &T2, &A);
			maxTo = max(maxTo, T2);
			for (int j = 0; j < A; j++) {
				int disk; scanf("%d", &disk);
				
				for (int k = T1; k < T2; k++) {
					adj[k * 2].push_back(disk * 2 + 1);
				}
			}
		}//입력정리 

		int sol = 0, time = -1;
		for (int i = 0; i <= maxTo; i++) {
			memset(visit, 0, sizeof(visit));
			sol += dfs(i *2);
			
			if (sol == N) {
				time = i;
				break;
			}
		}
		if (time > 0) {
			cout << time + 1 << endl;
		}
		else {
			cout << "-1"  << endl;
		}
		
	}
}
