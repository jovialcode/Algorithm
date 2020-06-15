#include <iostream>
using namespace std;
void Ascent_InsertionSort(int arr[], int n);
void Deascent_InsertionSort(int arr[], int n);

int main(void)
{
	
	int T; cin >> T;
	int **num = new int*[2];
	int sum = 0;
	for (int i = 0; i < 2; i++)
	{
		num[i] = new int[T];
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < T; j++)
		{
			cin >> num[i][j];
		}
	}

	Ascent_InsertionSort(num[0], T);
	Deascent_InsertionSort(num[1], T);

	for (int j = 0; j < T; j++)
	{
		sum += num[0][j] * num[1][j];
	}
	
	cout << sum <<endl;


	for (int i = 0; i < 2; i++)
	{
		delete[] num[i];
	}
	delete[] num;

	return 0;
}

void Ascent_InsertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void Deascent_InsertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}