#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

P com[1001];
bool stu[10001][721] = { 0, };

int main(){
	int N, K;
	while (1) {
		scanf("%d%d", &N, &K);
		if (N == 0 && K == 0) break;

		int r, q, t, n, m, s, ts,te;
		memset(stu, 0, sizeof(stu));
		
		scanf("%d", &r);
		for (int i = 0; i < r; i++) {
			scanf("%d%d%d%d", &t, &n, &m, &s);
			t -= 540;

			if ( (com[n].second != 0 && s == 1) || (com[n].second == 0 && s == 0)) continue;
			else if (com[n].second == 0 && s == 1) {
				com[n].second = m;
				com[n].first = t;
			}
			else if (com[n].second == m && s == 0) {
				for (int from = com[n].first; from < t; from++) stu[m][from] = 1;
				com[n].second = 0;
			}
		}
		scanf("%d", &q);
		
		for (int i = 0; i < q; i++) {
			int sol = 0;
			scanf("%d%d%d", &ts, &te, &m);
			ts -= 540; te -= 540;
			for (ts; ts < te; ts++) {
				if (stu[m][ts]) sol += 1;
			}
			cout << sol << endl;
		}

	}
}
