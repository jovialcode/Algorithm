#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int N, r[257];

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &r[i]);
	}
	//입력정리

	int ans = 0;
	for (int i = N; i > 1; i--) {
		int j;
		for (j = 1; j <= N; j++)
			if (r[j] == i) break;
		
		ans += r[j] - max(r[j - 1], r[j + 1]);

		for (; j <= N; j++) 
			r[j] = r[j + 1];
	}

	cout << ans;

}
