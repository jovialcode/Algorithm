#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[16];

void printArr(int printA[], int leng) {
	for (int i = 0; i < leng; i++) cout << printA[i] << " ";
	cout << endl;
}

void com(int printA[], int index, int n, int r, int target) {
	if (r == 0) printArr(printA, index);
	else if (target == n) return;
	else {
		printA[index] = arr[target];
		com(printA, index + 1, n, r - 1, target + 1);
		com(printA, index, n, r, target + 1);
	}
}



int main(void) {
	for (; cin >> n, n;) {
		memset(arr, 0, 16);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int printA[17] = { 0 };
		com(printA, 0, n, 6, 0);
		cout << endl;
	}
	return 0;
}
