#include <iostream>
#include <algorithm>
#include <cstring>
#define INFI 987654321
using namespace std;

struct brand {
	int pack;
	int single;
	bool operator <(const brand &other) const {
		return pack < other.pack;
	}
};
int N, M;
int dp[51][2];
brand b[51];

int sol(int index, int which) {
	if (index == M) return 0;

	int & ret = dp[index][which];
	if (ret != -1) return ret;

	ret = sol(index + 1, which);
	ret = MIN(ret, sol(index,1))
}

int main(void) {
	int ans = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d %d", &b[i].pack, &b[i].single);
	memset(dp, -1, sizeof(dp));
	//입력정리
	sort(b, b + M);
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		while (cnt <= N) {
			cnt += 6;
		}
	}
	return 0;
}