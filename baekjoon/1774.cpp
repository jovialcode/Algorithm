#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using P = pair<int, int>;

int N, M, p[1001];
vector<P> place;

struct Edge {
	int from, to;
	double cost;

	Edge(int f, int t, double c){
		from = f;
		to = t;
		cost = c;
	}

	bool operator()(const Edge &a, const Edge &b) const {
		return a.cost < b.cost;
	}
};

vector<Edge> adj;

int find(int x) {
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}

void uni(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
}

double getDist(pair<int, int> pla, pair<int, int> plb) {
	return sqrt(pow(pla.first - plb.first, 2) + pow(pla.second - plb.second, 2));
}

int main(){
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= 1000; i++) {
		p[i] = i;
	}//연결 끊기

	for (int i = 0; i < N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		place.push_back({ x,y });
	}
	for (int i = 0; i < M; i++) {
		int from, to; scanf("%d%d", &from, &to);
		int x = find(from);
		int y = find(to);
		if( x != y ) uni(from, to);
	}
	//입력정리

	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			P a = place[i], b = place[j];
			adj.push_back(Edge( i + 1, j + 1, getDist(a,b)));
		}
	}
	//거리 계산
	sort(adj.begin(), adj.end(), adj[0]);

	double sol = 0;
	for (int i = 0; i < adj.size(); i++) {
		Edge e = adj[i];
		int from = find(e.from);
		int to = find(e.to);

		if (from != to) {
			uni(e.from, e.to);
			sol += e.cost;
		}
	}

	printf("%0.2f", sol);
}
