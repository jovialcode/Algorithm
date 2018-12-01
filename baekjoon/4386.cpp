#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
using P = pair<double, double>;

int N, p[101];
vector<P> place;

struct Edge {
	int from, to;
	double cost;

	Edge(int f, int t, double c) {
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

double getDist(pair<double, double> pla, pair<double, double> plb) {
	return sqrt(pow(pla.first - plb.first, 2) + pow(pla.second - plb.second, 2));
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		double x, y; scanf("%lf%lf", &x, &y);
		place.push_back({ x,y });
	}//입력정리

	for (int i = 0; i <= 100; i++) {
		p[i] = i;
	}//연결 끊기

	//거리 계산
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			P a = place[i], b = place[j];
			adj.push_back(Edge(i, j, getDist(a, b)));
		}
	}

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

	printf("%0.2lf", sol);
}
