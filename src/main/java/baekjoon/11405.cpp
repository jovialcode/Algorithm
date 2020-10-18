#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;
const int MAX_N = 101;
const int INF = 987654321;
const int S = MAX_N * 2 + 1; //203
const int T = MAX_N * 2 + 2; //204
int N, M;
int flow[MAX_N * 3][MAX_N * 3], cost[MAX_N * 3][MAX_N * 3];
vector <vector<int>> adj;

int main() {
	scanf("%d%d", &N, &M);
	memset(flow, 0, sizeof(flow));
	memset(cost, 0, sizeof(cost));

	for (int i = 0; i < N; i++)
		scanf("%d", &flow[S][MAX_N + i] );

	for (int i = 0; i < M; i++)
		scanf("%d", &flow[i][T]);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[MAX_N + j][i]);
			
			flow[MAX_N + j][i] = INF;
			cost[i][MAX_N + j] = (-cost[MAX_N + j][i]);
		}
	}//입력정리 & 간선정리

	int sol = 0;

	while (1) {
		int dist[MAX_N * 3], prev[MAX_N * 3];
		bool inQ[MAX_N * 3] = {0,};

		fill(dist, dist + MAX_N * 3, INF);
		fill(prev, prev + MAX_N * 3, -1);

		queue<int> q;
		q.push(S);

		inQ[S] = true;
		dist[S] = 0;

		while (!q.empty()) {
			int here = q.front(); q.pop();
			inQ[here] = false;

			for (int i = 0; i < MAX_N * 2 + 3; i++) {
				if (flow[here][i] > 0 && dist[i] > dist[here] + cost[here][i]) {
					dist[i] = dist[here] + cost[here][i];
					prev[i] = here;

					if(!inQ[i]){
						q.push(i);
						inQ[i] = true;
					}
				}
			}
		}

		if (prev[T] == -1) break;

		int amount = INF;
		for (int i = T; i != S; i = prev[i]) {
			amount = min(amount, flow[prev[i]][i]);
		}

		for (int i = T; i != S; i = prev[i]) {
			flow[prev[i]][i] -= amount;
			flow[i][prev[i]] += amount;
		}

		sol += (dist[T]*amount);
	}
	cout << sol;
}
