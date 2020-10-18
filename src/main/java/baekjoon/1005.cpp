#include <iostream>
#include <queue>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int main(void) {
	int T; scanf("%d", &T);
	while (T--) {
		int N, M,W; 
		int t[1001], ind[1001] = { 0, }, sol[1001] = { 0, };
		vector<int> adj[1001];
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &t[i]);
			sol[i] = t[i];
		}
		for (int i = 0; i < M; i++) {
			int from, to; scanf("%d %d", &from, &to);
			adj[from].push_back(to);
			ind[to]++;
		}
		scanf("%d", &W);
		queue<int> q;
		//입력정리
		
		for (int i = 1; i <= N; i++) {
			if (ind[i] == 0) q.push(i);
		}
		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			for (int i = 0; i < adj[cur].size(); i++) {
				int to = adj[cur][i];
				ind[to]--;
				sol[to] = MAX(sol[to], sol[cur] + t[to]);
				if (ind[to] == 0) {
					q.push(to);
				}
			}
		}
		printf("%d\n", sol[W]);
	}
	return 0;
}