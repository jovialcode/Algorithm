#include <iostream>

using namespace std;
using LL = long long;

const int nanugi = 1000000007;
int N, l1[100001] ,l2[100001];
LL dp[100001][2];

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &l1[i]);
	for (int i = 0; i < N - 1; i++)
		scanf("%d", &l2[i]);
	//입력정리

	dp[0][0] = l1[0];
	dp[0][1] = l2[0];

	for (int i = 1; i < N; i++) {
		dp[i][0] = ((long long)(dp[i - 1][0] + dp[i - 1][1])*(l1[i] + l2[i - 1] - 1) + dp[i - 1][0]) % nanugi;
		dp[i][1] = (long long)(dp[i - 1][0] + dp[i - 1][1])*l2[i] % nanugi;
	}

	cout << dp[N - 1][0];
}
