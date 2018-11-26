#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int N, music[2002],dp[2002][2002];

int sol(int a, int b) {
	if (a == N || b == N) {
		return 0;
	}

	int &ret = dp[a][b];
	if (ret != -1) return ret;

	ret = INF;
	int next = a >= b ? a + 1 : b + 1;
	if (a == 0) {
		ret = min(ret, sol(next, b));
	}
	else {
		ret = min(ret, sol(next, b) + abs(music[next] - music[a]));
	}

	if (b == 0) {
		ret = min(ret, sol(a, next));
	}
	else {
		ret = min(ret, sol(a, next) + abs(music[next] - music[b]));
	}

	return ret;
}

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &music[i]);
	memset(dp, -1, sizeof(dp));
	//입력정리

	cout << sol(0, 0);
}
