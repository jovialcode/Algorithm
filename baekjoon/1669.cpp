#include <iostream>
using namespace std;
using ULL = unsigned long long;

int X, Y;

int main(){
	scanf("%d%d", &X, &Y);
	//입력정리 

	ULL dis = Y - X;
	ULL sum, N, i;

	for (i = 1; i <= 50000; i++) {
		unsigned long long val = i * i;
		if (val == dis) {
			cout << 2 * i - 1;
			return 0;
		}
		else if (val > dis) {
			N = i;
			break;
		}
	}
	sum = (N * N) + (N-1)*(N-1);

	if (sum/ 2 < dis) {
		cout << 2 * N - 1;
	}
	else {
		cout << 2 * (N - 1);
	}
	
}
