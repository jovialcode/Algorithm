#include <iostream>
#include <cstring>
#include <cmath>

#define MIN(a,b)(a>b? b:a)
#define INFI 9876543
using namespace std;

int numsSize;
int nums[100001];
int dp[100001][5][5];

int sol(int index, int L, int R) {
	if (index == numsSize)return 0;
	if (L != 0 && L == R) return INFI; // L == R 일 경우 INFI 로 반환한다.
	

	int &ret = dp[index][L][R];
	if (ret != -1) return ret;

	ret = INFI;
	if (nums[index] == L)
		ret = MIN(ret, sol(index + 1, L, R) + 1);
	if(nums[index] == R)
		ret = MIN(ret, sol(index + 1, L, R) + 1);
	
	if (L == 0) 
		ret = MIN(ret, sol(index + 1, nums[index], R) + 2);
	if(R == 0) 
		ret = MIN(ret, sol(index + 1, L, nums[index]) + 2);

	if (abs(nums[index] - R) == 1 || abs(nums[index] - R) == 3)
		ret = MIN(ret, sol(index + 1, L, nums[index]) + 3);
	if (abs(nums[index] - L) == 1 || abs(nums[index] - L) == 3)
		ret = MIN(ret, sol(index + 1, nums[index], R) + 3);

	if (abs(nums[index] - L) == 2)
		ret = MIN(ret, sol(index + 1, nums[index], R) + 4);
	if (abs(nums[index] - R) == 2)
		ret = MIN(ret, sol(index + 1, L,nums[index]) + 4);
	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	numsSize = 0;
	for (numsSize;; numsSize++) {
		int num; scanf("%d", &num);
		if (num == 0)
			break;
		nums[numsSize] = num;
	}
	//입력정리
	if (numsSize == 0)
		cout << "0";
	else 
		cout << sol(0,0,0)<< endl;
	return 0;
}
