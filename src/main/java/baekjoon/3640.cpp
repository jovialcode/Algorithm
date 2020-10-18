#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
using P = pair<int, int>;

const int INF = 987654321;
int f[2010][2010], cost[2010][2010];

int main() {
	
	int V, E;
	while (scanf("%d%d", &V, &E) != EOF) {

		vector<int> adj[2010];
		
		memset(f, 0, sizeof(f));

		for (int i = 0; i < E; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u = (u - 1) * 2 + 1;
			v = (v - 1) * 2;
			adj[u].push_back(v);
			adj[v].push_back(u);
			f[u][v] = 1;
			cost[u][v] = w;
			cost[v][u] = -w;
		}//입력정리

		for (int i = 0; i < V; i++) {
			f[i * 2][i * 2 + 1] = 1;
			adj[i * 2].push_back(i * 2 + 1);
			adj[i * 2 + 1].push_back(i * 2);
		}

		int sol = 0, S = 1, T = (V-1)*2;
		for (int k = 0; k < 2; k++) {
			
			int dist[2010], prev[2010];
			bool inQ[2010] = { false, };
			fill(dist, dist + 2010, INF);
			fill(prev, prev + 2010, -1);

			dist[S] = 0;
			queue<int> q;
			q.push(S);
			inQ[S] = true;

			while (!q.empty()) {
				int cur = q.front(); q.pop();
				inQ[cur] = false;

				for (int next : adj[cur]) {

					if (f[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]) {
						dist[next] = dist[cur] + cost[cur][next];
						prev[next] = cur;

						if (!inQ[next]) {
							q.push(next);
							inQ[next] = true;
						}
					}
				}
			}

			if (prev[T] == -1) break;

			for (int i = T; i != S; i = prev[i]) {
				sol += cost[prev[i]][i];
				f[prev[i]][i] -= 1;
				f[i][prev[i]] += 1;
			}
		}

		cout << sol << endl;
	}
}
