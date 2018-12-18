#include <bits/stdc++.h>
using namespace std;

int N, nums[2001];
bool visit[2001];

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &nums[i]);
	//입력정리

	sort(nums + 1, nums + N + 1);
	memset(visit, 0, sizeof(visit));

	int sol = 0;
	
	for (int k = 1; k <= N; k++) {
		int findN = nums[k],
			left = 1,
			right = N;

		while (left < right) {
			int curN = nums[left] + nums[right];

			if (curN < findN) {
				left += 1;
			}
			else if (curN > findN) {
				right -= 1;

			}
			else {
				
				if (left != k && right != k) {
					sol += 1; 
					break;
				}

				if (right == k) {
					right -= 1;
				}
				else if (left == k) {
					left += 1;
				}
			}
		}
	}
		
	cout << sol;


}
