#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
double c[1002];

int main() {
	scanf("%d%d", &N, &K);
	priority_queue<pair<double, int>> pq;
	for (int i = 0; i < N; i++) {
		int line; scanf("%d", &line);
		for (int j = 0; j < 3; j++) {
			int num;  scanf("%d", &num);
			if (j == 0) {
				c[line] += num * (100000);
			}
			else if (j == 1) {
				c[line] += num;
			}
			else {
				c[line] += num * 0.000001;
			}
		}
		pq.push({c[line],line});
	}//입력정리

	int cnt = 1, conti = 0;
	double preV = -1;
	while (!pq.empty()) {
		pair<double, int> p = pq.top(); pq.pop();
		double v = p.first;
		int line = p.second;

		if (preV == v) {
			conti += 1;
		}
		else {
			preV = v;
			conti = 0;
		}


		if (line == K) {
			cout << (conti > 0 ? cnt - conti : cnt);
			return 0;
		}

		

		cnt += 1;
	}
}
