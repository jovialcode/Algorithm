#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define MIN(a,b)(a>b?b:a)

using namespace std;
typedef pair<int, int> pii;

int N, M;
int map[1001][1001];
int dist[1001];
int visit[1001];

int main(){
	scanf("%d %d", &N, &M);
	memset(map, 0, sizeof(map));
	memset(dist, 9999999, sizeof(dist));
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		map[from][to] = cost;
		map[to][from] = cost;
	}//입력정리

	queue<int> q;
	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {

		int here = q.front(); q.pop();

		for (int i = 1; i <= N; i++) {
			if (i == here) continue;

			int next = map[here][i];

			if (next != 0 && dist[i] > dist[here] + next) {
				dist[i] = dist[here] + next;
				visit[i] = here;
				q.push(i);
			}	
		}
	}


	cout << N - 1 << endl;
	for (int i = 2; i <= N; i++) {
		cout << i<< " " << visit[i] << endl;
	}
	
	return 0;
}
