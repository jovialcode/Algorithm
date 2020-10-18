#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int N;
vector<int> tree(1000001);

void update(int i, int amount) {
	while (i <= MAXN){
		tree[i] += amount;
		i += (i & -i);
	}
	return;
}

int query(int i) {
	int res = 0;

	while (i > 0) {
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}

int main(){

	scanf("%d", &N);
	while (N--) {
		int A, B, C;
		scanf("%d", &A);
		if (A == 2) {
			scanf("%d%d", &B, &C);
			update(B, C);
		}
		else {
			scanf("%d", &B);
			int lo = 1, hi = MAXN;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				int s = query(mid);

				if (s >= B)
					hi = mid;
				else
					lo = mid + 1;
			}
			update(lo, -1);
			printf("%d\n", lo);
		}
	}
}
