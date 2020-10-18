#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int INF = 987654321;

int main(){
	int T; scanf("%d", &T);

	while (T--) {
		int N, D, C; scanf("%d%d%d", &N, &D, &C);
		int dist[10001];
		
		vector<vector<pii>> adj(N + 1);
		priority_queue<pii> pq;
		for (int i = 1; i <= N; i++) dist[i] = INF;

		for (int i = 0; i < D; i++) {
			int a, b, s; scanf("%d%d%d", &a, &b, &s);
			adj[b].push_back({ s,a }); // 초, To
		}//입력정리

		pq.push({ 0,C });

		dist[C] = 0;

		while (!pq.empty()) {
			pii p = pq.top(); pq.pop();
			int cur = p.second, took = -p.first;

			for (int i = 0; i < adj[cur].size(); i++) {
				int next = adj[cur][i].second, add = adj[cur][i].first;
				if (dist[next] > dist[cur] + add) {
					dist[next] = dist[cur] + add;
					pq.push({ -(took + add), next });
				}
			}
		}
		int cnt = 0, sol = 0;
		for (int i = 1; i <= N; i++)
			if (dist[i] != INF) { 
				cnt += 1; 
				sol = max(sol, dist[i]);
			}
		cout << cnt << " " << sol << endl;
	}
}
