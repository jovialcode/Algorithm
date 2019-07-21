#include <iostream>
#include <cstring>
using namespace std;
using LL = long long;

int N, from;
LL K, ans;
LL f[1000001];
const LL MOD = 1000000007;
int cycle_from[1000001], visit[1000001];
LL cycle[1000001];

int dfs(int current, int cnt) {
	if (visit[current]) {
		if (cycle_from[current] != from) return 0;
		return cnt - visit[current];
	}

	visit[current] = cnt;
	cycle_from[current] = from;
	return dfs(f[current], cnt + 1);
}
int main(){
	scanf("%d %lld", &N, &K);
	
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &f[i]);
	}

	memset(cycle, 0, sizeof(cycle));
	memset(visit, 0, sizeof(visit));
	memset(cycle_from, 0, sizeof(cycle_from));
	ans = 1;

	cycle[0] = 1;
	cycle[1] = K;
	cycle[2] = K * (K - 1) % MOD;
	cycle[3] = (cycle[2] * (K - 2)) % MOD; //cycle 일때

	for (int i = 4; i <= N; i++) {
		cycle[i] = cycle[i - 2] * (K - 1) + cycle[i - 1] * (K - 2);
		cycle[i] %= MOD;
	}
	//입력정리

	int cycleCnt = 0, aloneCnt = N ;
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;

		from = i;
		cycleCnt = dfs(i, 1);

		ans *= cycle[cycleCnt];
		ans %= MOD;

		aloneCnt -= cycleCnt;
	}

	for (int i = 1; i <= aloneCnt; i++) {
		ans *= (K - 1);
		ans %= MOD;
	}

	cout << ans << endl;

}
