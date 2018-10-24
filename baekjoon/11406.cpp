#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

int N, M;
int flow[302][302];
int pv[302];

vector<vector<int>> adj(302);

int main() {

	scanf("%d %d", &N, &M);
	memset(flow, 0, sizeof(flow));

	for (int i = 0; i < N; i++) {
		adj[N * 2].push_back(2 * i);
		adj[2 * i].push_back(N * 2);
		scanf("%d", &flow[N * 2][2 * i]);
	}// s -> node

	for (int i = 0; i < M; i++) {
		adj[2 * i + 1].push_back(N * 2 + 1);
		adj[N * 2 + 1].push_back(2 * i + 1);
		scanf("%d", &flow[2 * i + 1][N * 2 + 1]);
	}// node -> t

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			adj[2 * i + 1].push_back(2 * j);
			adj[2 * j].push_back(2 * i + 1);
			scanf("%d", &flow[2 * j][2 * i + 1]);
		}
	}// 간선 정리


	int sol = 0;
	while (1) {
		memset(pv, -1, sizeof(pv));
		queue<int> q;
		q.push(N * 2);

		while (!q.empty() && pv[N * 2 + 1] == -1) {
			int from = q.front(); q.pop();

			for (int next : adj[from]) {
				if (flow[from][next] > 0 && pv[next] == -1) {
					q.push(next);
					pv[next] = from;
				}
			}
		}

		if (pv[N * 2 + 1] == -1) break;

		int amount = INF;

		for (int it = N * 2 + 1; it != N * 2; it = pv[it]) {
			amount = min(flow[pv[it]][it], amount);
		}

		for (int it = N * 2 + 1; it != N * 2; it = pv[it]) {
			flow[it][pv[it]] += amount;
			flow[pv[it]][it] -= amount;
		}
		sol += amount;
	}
	cout << sol;
}
