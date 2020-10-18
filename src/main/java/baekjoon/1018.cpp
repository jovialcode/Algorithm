#include <iostream>
using namespace std;

#define MAX(a,b) (a>b? a:b)
#include <stdio.h>
char w[8][8] = { 'B','W','B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W','W', 'B','W', 'B','W', 'B','W', 'B', 'B','W', 'B','W', 'B','W', 'B','W', 'W','B','W','B','W','B','W','B' };
char b[8][8] = { 'W','B','W', 'B','W', 'B','W','B', 'B','W', 'B','W', 'B','W', 'B','W','W', 'B','W', 'B','W', 'B','W', 'B', 'B', 'W', 'B','W', 'B','W', 'B','W', 'W', 'B','W', 'B','W', 'B','W','B','B','W', 'B','W', 'B','W', 'B','W','W', 'B', 'W', 'B','W', 'B','W', 'B','B','W', 'B','W','B','W','B','W' };

char board[51][51];
int mn[50][50];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int i, j, k, p;
	for (i = 0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	for (i = 0; i<n - 7; i++)
	{
		for (j = 0; j<m - 7; j++)
		{
			int num1 = 0;
			int num2 = 0;
			for (p = 0; p<8; p++)
			{
				for (k = 0; k<8; k++)
				{
					if (b[p][k] == board[i + p][j + k])
						num1++;
					if (w[p][k] == board[i + p][j + k])
						num2++;
				}
			}
			mn[i][j] = MAX(num1, num2);
		}
	}
	int mx = 0;
	for (i = 0; i<n - 7; i++)
	{
		for (j = 0; j<m - 7; j++)
		{
			if (mx<mn[i][j])
				mx = mn[i][j];
		}
	}
	printf("%d", 64 - mx);
}