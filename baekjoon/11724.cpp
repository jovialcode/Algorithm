#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int visit[1001];
vector<vector<int>> map;

int main(){
	scanf("%d %d", &N, &M);
	
	map.resize(N + 1);
	memset(visit, 0, sizeof(visit));

	while (M--) {
		int from, to;
		scanf("%d %d", &from, &to);
		map[from].push_back(to);
		map[to].push_back(from);
	}

	int sol = 0;

	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		
		sol += 1;
		queue<int> q; q.push(i);

		while (!q.empty()) {
			int from = q.front(); q.pop();
			
			if (visit[from]) continue;
			visit[from] = 1;

			for (int to : map[from]) {
				if (visit[to]) continue;

				q.push(to);
			}
		}
	}

	if (sol == 0) {
		cout << "1";
	}
	else {
		cout << sol;
	}
	
}
