#include <bits/stdc++.h>
using namespace std;

int d, n;
int o[300001], p[300001];

int main(){
	scanf("%d%d", &d, &n);
	int minIdx = 0, minV = 0, pIdx = n;

	for (int i = 1; i <= d; i++) {
		scanf("%d", &o[i]);
	}

	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	//입력정리


	for (int i = 1; i <= n; i++) {

		if (p[i] <= minV) {
			pIdx -= 1;
		}
		else {
			for (int j = 1; j <= pIdx; j++) {
				if (p[i] > o[j]) {
					minV = p[i];
					pIdx = --j;
					break;
				}
			}
		}
	}

	cout << pIdx;

}
