#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

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
		int player[11][11],flow[MAX_N*3][MAX_N * 3];
		vector<vector<P>> adj(MAX_N * 3);
		for (int i = 0; i < MAX_N; i++)
			for (int j = 0; j < MAX_N; j++) 
				scanf("%d", &player[i][j]);
		//입력정리 
		
		
		for (int i = 0; i < MAX_N; i++) {
			adj[S].push_back({ i , 0 });
			adj[i].push_back({ S , 0});
			flow[S][i] = 1; // S-> player
			for (int j = 0; j < MAX_N; j++) {
				if (player[i][j] == 0) continue;
				adj[i].push_back({ MAX_N + j, 100 - player[i][j] });
				adj[MAX_N + j].push_back({ i,-(100 - player[i][j]) }); // augmenting
				flow[i][MAX_N + j] = 1; // player -> position
			}
		}

		for (int j = 0; j < MAX_N; j++) {
			adj[MAX_N + j].push_back({ T,0 });
			adj[T].push_back({ MAX_N + j,0 });
			flow[MAX_N + j][T] = 1; // position -> T
		}//간선정리

	
		int sol = 11 * 100;
		while (1)
		{
			bool inQ[MAX_N * 3] = {0,};
			int dist[MAX_N * 3], prev[MAX_N * 3];
			queue<int> q;

			for (int i = 0; i < MAX_N * 3; i++) dist[i] = INF;
			memset(prev, -1, sizeof(prev));

			dist[S] = 0;
			inQ[S] = true;

			q.push(S);

 			while (!q.empty() && prev[T] == -1)
			{
				int here = q.front(); q.pop();
				inQ[here] = false;

				for (auto &p : adj[here])
				{
					int next = p.first, add = p.second;

					if (flow[here][next] > 0 && dist[next] > dist[here] + add)
					{
						dist[next] = dist[here] + add;
						prev[next] = here;

						if (!inQ[next])
						{
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

		cout << sol;

	}
}
