#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using P = pair<int, int>;

const int INF = 987654321;
int N, M;
vector<P> adj[201];

int main(){
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);
		adj[from].push_back({to,cost});
		adj[to].push_back({ from,cost });
	}//입력정리


	int prev[201][201];
	fill_n(&prev[0][0], 201 * 201, -1);
	for (int start = 1; start <= N; start++) {
		int dist[201];
		queue<int> q;
		fill(dist, dist + 201, INF);
		
		q.push(start);
		dist[start] = 0;

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (P a : adj[cur]) {
				int next = a.first, cost = a.second;

				if (dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					prev[start][next] = cur;
					q.push(next);
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (prev[j][i] == -1) {
				cout << "-" << " ";
			}
			else {
				cout << prev[j][i] << " ";
			}
		}
		cout << endl;
	}

}
