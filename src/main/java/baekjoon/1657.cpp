#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int N,M, dp[16 * 16][1 << 16];
char board[16][16];

const int score[5][5] = {
	{ 10,8,7,5,1 },
	{ 8,6,4,3,1 },
	{ 7,4,3,2,1 },
	{ 5,3,2,2,1 },
	{ 1,1,1,1,0}
};

int sol(int num, int state) {
	if (num == N*M) return 0;

	int &ret = dp[num][state];
	if (ret != -1) return ret;

	ret = 0;
	if (state & 1)
		ret = MAX(ret, sol(num + 1, (state >> 1)));
	else {
		int x = num / M;
		int y = num % M;
		if (x<N - 1)
			ret = MAX(ret, sol(num + 1, (state >> 1) | (1 << (M - 1))) + score[board[x][y] - 'A'][board[x + 1][y] - 'A']);
		if ((num%M) != (M - 1) && (state & 2) == 0)
			ret = MAX(ret, sol(num + 2, state >> 2) + score[board[x][y] - 'A'][board[x][y + 1] - 'A']);
	}
	ret = MAX(ret, sol(num + 1, (state >> 1)));
	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &N,&M);getchar();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch; scanf("%1c", &ch);
			if (ch == 'F')
				board[i][j] = 'E';
			else
				board[i][j] = ch;
		}
		getchar();
	}

	//입력정리
	cout << sol(0, 0);
	return 0;

}
