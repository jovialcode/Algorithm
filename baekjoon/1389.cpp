#include <iostream>
using namespace std;

int floyds(int **adj,int size)
{
	int i, j, k,pos;
	int min = 99999999;
	for (k = 0; k < size; k++)
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (((adj[i][k] * adj[k][j]) != 0) && (i != j))
				{
					if ((adj[i][k] + adj[k][j] < adj[i][j]) || (adj[i][j] == 0))
						adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

	for (i = 0; i < size; i++)
	{
		int value = 0;
		for (j = 0; j < size; j++)
		{
			value += adj[i][j];
		}
		if (min > value)
		{
			min = value;
			pos = i;
		}
	}
	return pos;
}

int main(void)
{
	int size,T,sol; cin >> size>>T;
	int **adj;
	adj = new int*[size];
	for (int i = 0; i < size; i++)
		adj[i] = new int[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			adj[i][j] = 0;
	}

	for (int i = 0; i < T; i++)
	{
		int a, b; cin >> a >> b;
		adj[a - 1][b - 1] = 1;
		adj[b - 1][a - 1] = 1;
	}

	sol = floyds(adj, size);
	cout << sol+1<<endl;
	for (int i = 0; i < size; i++)
		delete[] adj[i];
	delete adj;
	return 0;
}
