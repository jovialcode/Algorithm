#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX(a,b)(a>b?a:b)

using namespace std;
typedef pair<int, int> pii;

int N, M;
vector<vector<pii>> node;

int main(){
	scanf("%d %d", &N, &M);
	node.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		node[from].push_back({cost,to});
		node[to].push_back({ cost,from });
	}
  //

	int visit[100001] = { 0, };
	priority_queue<pii> pq;
	int sol = 0, bigOne = 0;
	pq.push({ 0,1 });
	

	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int cost = -p.first
		  , here = p.second;

		if (visit[here]) continue;
		visit[here] = 1; 
		
		sol += cost; 
		bigOne = MAX(bigOne, cost);

		for (int next = 0; next < node[here].size(); next++) {
			int to = node[here][next].second
			  , add = node[here][next].first;

			if (visit[to]) continue;
			pq.push({-add, to});
		}
	}

	cout << sol - bigOne;

}
