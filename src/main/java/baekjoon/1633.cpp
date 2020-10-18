#include <iostream>
#include <cstring>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int N;
int	player[1001][2];
int dp[1001][16][16];

int sol(int index, int w, int b) {
	if (w == 15 && b == 15) return 0;
	if (index == N) return 0;

	int &ret = dp[index][w][b];
	if (ret != -1) return ret;

	ret = sol(index + 1, w, b);

	if (w < 15 && b == 15) {
		ret = MAX(ret, sol(index + 1, w + 1, b) + player[index][0]);
	}else if(w == 15 && b<15){
		ret = MAX(ret, sol(index + 1, w, b +1) + player[index][1]);
	}
	else {
		ret = MAX(ret, sol(index + 1, w, b + 1) + player[index][1]);
		ret = MAX(ret, sol(index + 1, w + 1, b) + player[index][0]);
	}

	return ret;
}

int main(void) {
	memset(dp, -1, sizeof(dp));
	N = 0;
	while (cin>>player[N][0]>>player[N][1],!cin.eof()){
		N++;
	}
	cout << sol(0, 0, 0);
	return 0;
}
