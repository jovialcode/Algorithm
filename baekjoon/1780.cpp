#include <iostream>
using namespace std;

int board[2187][2187];
int n;
int countN[3] = { 0 };

bool check(int x,int y, int sizeN) {
	for (int i = x; i < x+ sizeN; i++)
		for (int j = y; j < y+ sizeN; j++)
			if (board[x][y] != board[i][j])
				return false;
	return true;
}

void solve(int x, int y, int sizeN) {
	//기저 사례 
	if (sizeN == 1 ||check(x,y, sizeN)){
		if (board[x][y] == (-1)) countN[2]++;
		else countN[board[x][y]]++;
		return ;
	}

	int ret = 0;
	for (int i = x; i < x+sizeN; i+=(sizeN/3))
		for (int j = y; j < y + sizeN; j += (sizeN / 3)) {
			if (sizeN >= 1 && !check(x,y, sizeN)) {
				solve(i,j, sizeN / 3);
			}
		}
	return ;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	solve(0, 0, n);
	cout << countN[2] << endl<< countN[0]<<endl<< countN[1];

	return 0;
}
