#include <iostream>
#include <algorithm>
using namespace std;

int N,M, nums[10001];

int main() {
	int maxV = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { 
		scanf("%d", &nums[i]);
		maxV = max(maxV, nums[i]);
	}
	scanf("%d", &M);
	//입력정리

	int left = 0, right = M, mid = (left + right) / 2;

	while( left <= right ){
		int sum = 0;

		for (int j = 0; j < N; j++) {
			nums[j] > mid ? sum += mid : sum += nums[j];
		}

		if (sum > M) {
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else {
			left = mid + 1;
			mid = (left + right) / 2;
		}
	}

	if (maxV < mid) {
		cout << maxV;
	}
	else {
		cout << mid << endl;
	}
}
