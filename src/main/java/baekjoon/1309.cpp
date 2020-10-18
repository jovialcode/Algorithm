#include <iostream>
using namespace std;

int main(void)
{
	int T; cin >> T;
	int dp[100001] = { 0 };
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i <= T; i++)
		dp[i] = (dp[i - 1] * 2 + dp[i - 2])%9901;
	cout << dp[T]%9901;
	return 0;
}
