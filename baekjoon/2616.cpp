#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int N,M;
int train[50001];
int MSum[50001];
int dp[50001][3];

int sol(int pos, int cnt) {
	if (cnt == 3 || pos > N)
		return 0;
	int &ret = dp[pos][cnt];
	if (ret != -1) return ret;
	ret = 0;
	
	ret = MAX(ret, sol(pos + 1, cnt));
	ret = MAX(ret, sol(pos + M, cnt + 1) + MSum[pos]);
	 
	return ret;
}
int main(void) {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; cin >> train[i++]);
	cin >> M;

	for (int i = 0; i <= N - M; i++) {
		for (int j = i; j < (i+M); j++) {
			MSum[i] += train[j];
		}
	}
	//입력 및 정리 
	cout << sol(0, 0);
	return 0;
}
