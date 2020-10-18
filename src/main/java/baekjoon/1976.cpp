#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N,M, city[202][202], p[202];
vector<int> tour;

int find(int x) {
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	p[x] = y;
}

int main(){
	scanf("%d%d", &N,&M);

	for(int i = 1; i<=N; i++)
		p[i] = i;
	//초기화

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &city[i][j]);
		}
	}//입력정리

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!city[i][j]) continue;

			int x = find(i);
			int y = find(j);

			if (x != y) {
				merge(x, y);
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int num; scanf("%d", &num);
		tour.push_back(num);
	}

	for (int i = 0; i < tour.size() - 1; i++) {
		int from = tour[i], to = tour[i + 1];
		if (find(from) != find(to)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
}

