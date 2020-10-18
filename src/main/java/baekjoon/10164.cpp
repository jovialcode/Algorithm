#include <iostream>
using namespace std;

int N, M;
int point;
int grid[17][17];
int dp[17][17] = { 0 };

int main(void) {

	cin >> N >> M>>point;

	for (int i = 0; i < N; dp[i++][0] = 1);
	for (int i = 0; i < M; dp[0][i++] = 1);

	if (point != 0) {
		point--;
		int pointX = point / M;
		int	pointY = point%M ;
		for (int i = 1; i <= pointX; i++)
			for (int j = 1; j <= pointY; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

		for (int i = pointX; i < N; dp[i++][pointY] = dp[pointX][pointY]);
		for (int i = pointY; i < M; dp[pointX][i++] = dp[pointX][pointY]);

		for (int i = pointX+1; i <N; i++)
			for (int j = pointY+1; j <M; j++)
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	}
	else 
		for (int i = 1; i < N; i++) 
			for (int j = 1; j < M; j++) 
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
	cout << dp[N - 1][M - 1];
	return 0;
}
