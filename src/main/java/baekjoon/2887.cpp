#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N;
vector<vector<pii>> map;
vector<pii> vp[3];
priority_queue<pii> pq;
int visit[100001];

void makeEdge();

int main(){
	
	scanf("%d", &N);
	map.resize(N + 1);
	
	for (int i = 1; i <= N; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		vp[0].push_back({ x,i });
		vp[1].push_back({ y,i });
		vp[2].push_back({ z,i });
	}
	//입력정리
	makeEdge();

	memset(visit, 0, sizeof(visit));
	pq.push({ 0,1 });
	LL sol = 0;

	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();

		int cost = -(p.first)
			, here = p.second;

		if (visit[here]) continue;
		visit[here] = 1;
		sol += cost;

		for (auto next : map[here]) {
			if (visit[next.second]) continue;

			pq.push({ -next.first,next.second });
		}
	}

	cout << sol;

	return 0;
}

void makeEdge() {
	
	for (int i = 0; i < 3; i++) {
		sort(vp[i].begin(), vp[i].end(), greater<pii>());

		for (int j = 0; j < vp[i].size() - 1; j++) {
			pii from = vp[i][j], to = vp[i][j + 1];
			int dist = abs(from.first - to.first);
			map[from.second].push_back({ dist,to.second });
			map[to.second].push_back({ dist,from.second });
		}
	}
	return;
}
