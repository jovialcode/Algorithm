#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using LL = long long;
LL const INF = -1e18;
int A, B, C;
LL dp[3002][3002];
string str1, str2;

LL sol(int a, int b) {

	if (a > str1.size() || b > str2.size())return INF;
	if (a == str1.size() && b == str2.size())return 0;

	LL &ret = dp[a][b];
	if (ret != INF) return ret;

	if (str1[a] == str2[b]) {
		ret = max(ret, sol(a + 1, b + 1) + A);
	}
	else {
		ret = max(ret, sol(a + 1, b) + B);
		ret = max(ret, sol(a, b + 1) + B);
		ret = max(ret, sol(a + 1, b + 1) + C);
	}
	return ret;
}

int main(){
	scanf("%d%d%d", &A, &B, &C); getchar();
	getline(cin, str1); getline(cin, str2);
	
	for (int i = 0; i < 3002; i++) {
		for (int j = 0; j < 3002; j++) {
			dp[i][j] = INF;
		}
	}
	//입력정리
	cout << sol(0, 0);
}
