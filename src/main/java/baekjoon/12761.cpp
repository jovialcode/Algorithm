#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int, int> P;
const int MAX_N = 100001;
int visit[100001];
int A, B, N, M;

int main(){
	scanf("%d %d %d %d", &A, &B, &N, &M);
	priority_queue < P, vector<P>, greater<P>> pq;
	fill(visit, visit + MAX_N, 0);
	//입력정리 

	pq.push({0,N});
	while (!pq.empty()) {
		P p = pq.top(); pq.pop();
		int step = p.first, pos = p.second;

		if (pos > 100000 || pos < 0 || visit[pos]) continue;
		visit[pos] = 1;

		if (pos == M) { 
			printf("%d", step); 
			break; 
		}
		for (int i = 0; i < 2; i++) {
			pq.push({ step + 1, pos + 1 }); //우
			pq.push({ step + 1, pos - 1 }); //좌

			pq.push({ step + 1, pos - A });
			pq.push({ step + 1, pos - B });

			pq.push({ step + 1, pos + A });
			pq.push({ step + 1, pos + B });

			pq.push({ step + 1, pos * A });
			pq.push({ step + 1, pos * B });
		}

	}
}
