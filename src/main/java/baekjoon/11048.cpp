#include <iostream>
#include <algorithm>
#define max3(a,b,c) (max(a,max(b,c)))
using namespace std;

int main(void)
{
	int row, col; cin >> row >> col;
	int **visit = new int*[row+1];
	int **candy = new int*[row+1];
	for (int i = 0; i <= row; i++) {
		visit[i] = new int[col+1];
		candy[i] = new int[col+1];
	}

	for (int i = 0; i < row; i++) 
		for (int j = 0; j < col; j++) 
			cin >> candy[i][j];

	for (int i = 0; i <= row; i++)
		for (int j = 0; j <= col; j++)
			visit[i][j] = 0;
	
	for(int i = 1; i<=row; i++)
		for (int j = 1; j <= col; j++) 
			visit[i][j] = max3(visit[i - 1][j], visit[i][j - 1], visit[i - 1][j - 1]) + candy[i-1][j-1];

	cout << visit[row][col];


	for (int i = 0; i <= row; i++) {
		delete visit[i];
		delete candy[i];
	}
	delete visit, candy;
	return 0;
}
