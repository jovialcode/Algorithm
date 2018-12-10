#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int const MAX_V = 900;
int N, P, flow[MAX_V][MAX_V];
vector<int> adj[MAX_V];

int main(){
	scanf("%d%d", &N, &P);
	for (int i = 0; i < P; i++) {
		int from, to; scanf("%d%d", &from, &to);
		from = (from - 1) * 2 + 1;
		to = (to - 1) * 2;

		adj[from].push_back(to);
		adj[to].push_back(from);
		adj[to + 1].push_back(from - 1);
		adj[from - 1].push_back(to + 1);

		flow[from][to] = 1;
		flow[to + 1][from - 1] = 1;
	}//입력정리

	for (int i = 0; i < N; i++) {
		adj[i * 2].push_back(i * 2 + 1);
		adj[i * 2 + 1].push_back(i * 2);
		flow[i * 2][i * 2 + 1] = 1;
	}//2개의 정점으로 나누기

	int sol = 0, S = 1, T = 2;
	while (1) {
		int prev[MAX_V];
		fill(prev, prev + MAX_V, -1);
		queue<int> q;
		q.push(S);

		while (!q.empty() && prev[T] == -1) {
			int cur = q.front(); q.pop();
			for (int next : adj[cur]) {
				if (flow[cur][next] > 0 && prev[next] == -1) {
					prev[next] = cur;
					q.push(next);
				}
			}
		}
		if (prev[T] == -1) break;

		for (int i = T; i != S; i = prev[i]) {
			flow[prev[i]][i] -= 1;
			flow[i][prev[i]] += 1;
		}
		sol += 1;
	}

	cout << sol;
}
