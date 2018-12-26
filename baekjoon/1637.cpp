#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int MAXN = 20002, INF = 2147483647;
int N;
LL A[MAXN],B[MAXN],C[MAXN];

LL sol(LL num) {

	LL ret = 0;
	for (int i = 0; i < N; i++) {
		if (num >= A[i]) {
			ret += (min(C[i], num) - A[i]) / B[i] + 1;
		}
	}

	return ret;
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld%lld%lld", &A[i], &C[i], &B[i]);
	}
	//입력정리

	LL left = 1, right = INF;
	while (left < right) {
		LL mid = (left + right) / 2;
		if (sol(mid) % 2 == 0) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	if (left == INF) {
		cout << "NOTHING";
	}
	else {
		cout << left << " " << sol(left) - sol(left - 1);
	}
	
}
