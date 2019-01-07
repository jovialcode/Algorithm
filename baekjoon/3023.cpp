#include <bits/stdc++.h>
using namespace std;

int main(){
	char board[104][104];
	int R, C,A,B;
	scanf("%d%d", &R, &C); getchar();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char c; scanf("%1c", &c);
			board[i][j] = c;
			board[i][C * 2 - j - 1] = c;
			board[R * 2 - i - 1][j] = c;
			board[R * 2 - i - 1][C * 2 - j - 1] = c;
		}
		getchar();
	}

	scanf("%d%d", &A, &B);
	if (board[A - 1][B - 1] == '.')  board[A - 1][B - 1] = '#';
	else board[A - 1][B - 1] = '.';

	for (int i = 0; i < R * 2; i++) {
		for (int j = 0; j < C * 2; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
