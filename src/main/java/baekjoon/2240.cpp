#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int T, W;
int plum[1001];
int dp[1001][31][2];


int sol(int start, int life, int which) {
	if (start == T) return 0;
	if (life < 0) return 0;
	
	int &ret = dp[start][life][which];
	if (ret != -1) return ret;
	
	
	if (plum[start] == which) {
		ret= MAX(ret, sol(start + 1, life, which) + 1);
		if (life)
			ret = MAX(ret, sol(start + 1, life - 1, 3-which) + 1);
	}
	else {
		ret = MAX(ret, sol(start + 1, life, which));
		if (life)
			ret = MAX(ret, sol(start + 1, life - 1, 3-which));
	}
	return ret;
}
int main(void)
{
	memset(dp, -1, sizeof(dp));
	cin >> T >> W;
	for (int i = 0; i < T;i++ )
		scanf("%d", &plum[i]);

	cout<<MAX(sol(0, W, 1),sol(0,W-1,2));

	return 0;
}
