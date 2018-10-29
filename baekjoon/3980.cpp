#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;
typedef pair<int, int> P;

const int INF = 987654321;
const int MAX_N = 11;
const int S = MAX_N * 2 + 1; // 23
const int T = MAX_N * 2 + 2; // 24

int main()
{
	int TC;scanf("%d", &TC);
	while (TC--){
		int flow[MAX_N * 3][MAX_N * 3], cost[MAX_N * 3][MAX_N * 3];
		vector<vector<int>> adj(MAX_N * 3);

		memset(flow, 0, sizeof(flow));
		memset(cost, 0, sizeof(cost));

		for (int i = 0; i < MAX_N; i++) {
			adj[MAX_N + i].push_back(T);
			adj[T].push_back(MAX_N + i);
			adj[S].push_back(i);
			adj[i].push_back(S);

			flow[S][i] = 1; // S-> player
			flow[MAX_N + i][T] = 1; // position -> T
			for (int j = 0; j < MAX_N; j++) {
				int num;scanf("%d", &num);

				if (num == 0) continue;
				adj[i].push_back(MAX_N + j);
				adj[MAX_N + j].push_back(i); // augmenting
				flow[i][MAX_N + j] = 1; // player -> position
				
				cost[i][MAX_N + j] = 100 - num;
				cost[MAX_N + j][i] = -(100 -num);
			}
		}
		//입력정리 
	
		int sol = 100 * 11;
		while (1)
		{
			bool inQ[MAX_N * 3] = {0,};
			int dist[MAX_N * 3], prev[MAX_N * 3];
			queue<int> q;

			fill(dist, dist + MAX_N * 3, INF);
			fill(prev, prev + MAX_N * 3 , -1);

			dist[S] = 0;
			inQ[S] = true;

			q.push(S);

 			while (!q.empty() && prev[T] == -1)
			{
				int here = q.front(); q.pop();
				inQ[here] = false;

				for (int next : adj[here])
				{
					int add = cost[here][next];

					if (flow[here][next] > 0 && dist[next] > dist[here] + add)
					{
						dist[next] = dist[here] + add;
						prev[next] = here;

						if (!inQ[next]){
							q.push(next);
							inQ[next] = true;
						}
					}
				}
			}
			if (prev[T] == -1)
				break;

			for (int i = T; i != S; i = prev[i])
			{
				flow[prev[i]][i] -= 1;
				flow[i][prev[i]] += 1;

			}
			sol -= dist[T];
		}

		printf("%d", sol);

	}
}
