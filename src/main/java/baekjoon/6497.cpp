#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Edge{
	int from, to, cost;

	bool operator()(const Edge &a, const Edge &b) const{
		return a.cost < b.cost;
	}
};

int p[200001];

int find(int x){
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}

void uni(int x, int y){
	x = find(x);
	y = find(y);
	p[x] = y;
}


int main(){
	int M, N; 
	while (1) {
		scanf("%d%d", &M, &N);
		if (M + N == 0) break;

		int sumV = 0;
		vector<Edge> adj;
		

		for (int i = 0; i < N; i++) {
			int from, to, cost; scanf("%d%d%d", &from, &to, &cost);
			sumV += cost;
			adj.push_back({from,to,cost});
		}//입력정리

		sort(adj.begin(), adj.end(), adj[0]);
		//오름차순 정렬
		
		for (int i = 0; i < M; i++) {
			p[i] = i;
		}//정점 단절

		int sol = 0;
		for (int i = 0; i < N; i++) {
			Edge e = adj[i];
			int from = find(e.from);
			int to = find(e.to);

			if (from != to) {
				uni(e.from, e.to);
				sol += e.cost;
			}
		}
		//크루스칼
		cout << sumV - sol << endl;
	}

}
