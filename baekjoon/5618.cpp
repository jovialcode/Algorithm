#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int N, nums[4], maxN = 0; scanf("%d", &N);
	for (int i = 1; i <= N; i++) { 
		scanf("%d", &nums[i]);
		maxN = max(maxN, nums[i]);
	}
	//입력정리

	for (int i = 1; i <= maxN; i++) {
		for (int j = 1; j <= N; j++) {
			if (nums[j] % i != 0) break;
			if (j == N) cout << i << endl;
		}
	}

}
