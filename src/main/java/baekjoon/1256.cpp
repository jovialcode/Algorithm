#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;

int N, M, K;
int dp[202][202];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	//입력정리

	for (int i = 0; i <= 200; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = min((dp[i - 1][j - 1] + dp[i - 1][j]), (int)1e9);
	}

	if (dp[N+M][M] < K) {
		cout << "-1";
	}
	else {
		int t = N + M;

		for (int i = 0; i < t; i++) {
			if (K > dp[N + M - 1][M]) {
				cout << 'z';
				K -= dp[N + M - 1][M];
				M--;
			}
			else {
				cout << 'a';
				N--;
			}
		}
	}

}
