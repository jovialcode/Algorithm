#include <iostream>
#include <cstring>
using namespace std;

int b[3], dp[502][502];

int main(){
	for (int i = 0; i < 3; i++) {
		scanf("%d", &b[i]);
	}//입력정리

	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			dp[i][j] = 0;
			for (int k = 0; k < 3; k++) {
				if (i - b[k] >= 0 && dp[i - b[k]][j] == 0)
					dp[i][j] = 1;
				if (j - b[k] >= 0 && dp[i][j - b[k]] == 0)
					dp[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		int k1, k2; scanf("%d%d", &k1, &k2);
		printf("%c\n", dp[k1][k2] == 1 ? 'A' : 'B');
	}
}
