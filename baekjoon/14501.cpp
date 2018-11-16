#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, c[16], p[16];
int dp[17];

int sol(int index) {
	if (index > N + 1) return 0;

	int & ret = dp[index];
	if (ret != -1 ) return ret;
	
	ret = sol(index + 1);
	if (index + c[index] <= N+1) {
		ret = max(ret, sol(index + c[index]) + p[index]);
	}
	return ret;
}
int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &c[i], &p[i]);
	}//입력정리
	memset(dp, -1, sizeof(dp));

	cout << sol(1);

}
