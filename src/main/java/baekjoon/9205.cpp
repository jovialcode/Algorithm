#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

const int H = 102, F = 103;
int adj[105][105];
vector<P> beer;
P h, f;
int dist(int fx, int fy, int sx, int sy) {
	return abs(sx - fx) + abs(sy - fy);
}


int main(){

	int T; scanf("%d", &T);

	while (T--) {
		int N; scanf("%d", &N);
		memset(adj, 0, sizeof(adj));
		beer.clear();

		scanf("%d%d", &h.first, &h.second); //집
		for (int i = 0; i < N; i++) {
			int x, y; scanf("%d%d", &x, &y);
			beer.push_back({ x,y });
		}//편의점
		scanf("%d%d", &f.first, &f.second);//페스티벌
		//입력정리

	
		for (int i = 0; i < beer.size(); i++) {
			P cur = beer[i];
			if (dist(cur.first, cur.second, h.first, h.second) <= 1000) adj[H][i] = adj[i][H] = 1;
			if (dist(cur.first, cur.second, f.first, f.second) <= 1000) adj[F][i] = adj[i][F] = 1;

			for (int j = i + 1; j < beer.size(); j++) {
				P next = beer[j];
				if (dist(cur.first, cur.second, next.first, next.second) <= 1000) {
					adj[i][j] = adj[j][i] = 1;
				}
			}
		}
		if (dist(f.first, f.second, h.first, h.second) <= 1000)adj[H][F] = adj[F][H] = 1;
    //그래프 형성

		bool visit[105] = { 0, };
		queue<int> q;
		q.push(H);
		visit[H] = true;

		while (!q.empty()) {
			int cur = q.front(); q.pop();

			if (cur == F) break;

			for (int i = 0; i < 105; i++) {
				if (visit[i] || i == cur || adj[cur][i] == 0) continue;
				
				visit[i] = true;
				q.push(i);
			}
		}
		
		if (visit[F]) cout << "happy" << endl;
		else cout << "sad" << endl;
	}
}
