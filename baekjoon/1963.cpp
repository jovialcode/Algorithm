#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
using P = pair<int, int>;

bool prime[10001];

void eratostenes() {
	memset(prime, true, sizeof(prime));
	for (int i = 2; i <= 10000; i++) {
		if (prime[i]) {
			for (int j = i*i ; j < 10001; j += i) {
				prime[j] = false;
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	eratostenes();
	//에라토스테네스 체

	while (T--) {
		int a, b; scanf("%d%d", &a, &b);
		bool visit[10001] = { false, };
		//입력정리

		priority_queue<P> pq;
		pq.push({0,a});
		int sol = -1;
		while (!pq.empty()) {
			P cur = pq.top(); pq.pop();
			int cnt = -cur.first, num = cur.second;

			if (num == b) {
				sol = cnt;
				break;
			}
			int arr[4];
		
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					arr[0] = num / 1000,
					arr[1] = (num%1000) / 100,
					arr[2] = (num%1000) %100/10,
					arr[3] = num % 10;
					arr[i] = j;
					int nextNum = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
					if (prime[nextNum] && !visit[nextNum] && nextNum >= 1000) {
						visit[nextNum] = 1;
						pq.push({-(cnt + 1), nextNum});
					}
				}
			}
		}
		if (sol != -1) {
			cout << sol << endl;
		}
		else {
			cout << "Impossible" << endl;
		}
	}
}

