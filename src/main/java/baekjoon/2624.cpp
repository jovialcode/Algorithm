#include <iostream>
#include <cstring>
using namespace std;

struct coinType {
	int value, cnt;
};

int target, N;
coinType coins[101];
int dp[10001][101];

int sol(int money,int type) {

	if (money == target) return 1;
	if (money > target) return 0;
	if (type == N) return 0;
	

	int &ret = dp[money][type];
	if (ret != -1) return ret;

	ret = 0;
	for (int i = 0; i <= coins[type].cnt; i++) {
		int add = i*coins[type].value;
		if (add > target) break;
		ret += sol(money + add,type+1);
	}
	return ret;
}
int main(void) {
	scanf("%d %d", &target, &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &coins[i].value, &coins[i].cnt);
	}
	memset(dp, -1, sizeof(dp));
	//입력 정리
	printf("%d\n", sol(0,0));

}
