#include <iostream>
#include <cstring>
#define MIN(a,b)(a>b?b:a)
using namespace std;

int N,M;
bool nums[11];
bool checking(int num) {
	while (num > 0) {
		int see = num % 10;
		if (!nums[see]) return false;
		num /= 10;
	}
	return true;
}

int len(int num) {
	int cnt = 0;
	while (num > 0) {
		cnt++;
		num /= 10;
	}
	return cnt;
}
int main(void) {
	scanf("%d %d", &N,&M);
	memset(nums, true, sizeof(nums));
	
	for (int i = 0; i < M; i++) {
		int num; scanf("%d", &num);
		nums[num] = false;
	}
	int cnt = 0, leftStart = N, rightStart = N;
	//입력정리
	
	while (1) {
		if (leftStart == 100 || rightStart == 100)
			break;
		if (checking(leftStart)){
			cnt += len(leftStart);
			break;
		}
		else if (checking(rightStart)) {
			cnt += len(rightStart);
			break;
		}
		else {
			cnt++; leftStart--; rightStart++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}