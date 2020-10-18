#include <iostream>
#include <cstring>
#include <cmath>
#define MIN(a,b)(a>b?b:a)
#define DOB(a,b)((a-b)*(a-b))
using namespace std;

int N, M;
int name[1001];
int dp[1001][1001];

int sol(int size, int index) {
	if (index == N || M-size<0)
		return 0;
	int &ret = dp[size][index];
	if (ret != -1) return ret;

	ret = 987654321;
	if (size == 0)
		ret = MIN(ret, sol(name[index], index + 1));
	else if (size + 1 + name[index] <= M)
		ret = MIN(ret, sol(size + 1 + name[index], index + 1));
	else
		ret = MIN(ret, sol(0, index)+DOB(M,size));

	ret = MIN(ret, sol(name[index], index+1) + DOB(M, size));

	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> name[i];

	int ans = sol(0, 0);
	/*for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	cout << ans;
	return 0;
}
