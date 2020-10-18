#include <iostream>
#include <list>
#include <cstring>
#define MAX(a,b) (a>b?a:b)
using namespace std;

int N;
int board[16][16],dp[16][16];

int sol(int row, int col) {
	if (row == N && col == N) return 0;
	if (row == N || col == N) return 0;

	int &ret = dp[row][col];
	if (ret != 0) return ret;

	if (ret >= board[row][col + 1]) {
		ret = board[row][col + 1];
		return sol(row, col + 1);
	}
	else {
		return sol(row, col + 1);
	}
	return ret;
}

int main(void) {
	memset(dp, 0, sizeof(dp));
	scanf("%d", &N); //예술가 수



	return 0;
}