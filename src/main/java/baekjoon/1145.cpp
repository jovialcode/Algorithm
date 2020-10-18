#include <iostream>
using namespace std;
long long gcd(long long a, long long b) { return(b ? gcd(b, a%b) : a); }
long long maxN = 1000000;

long long LCD(int a, int b) {
	return (a*b) / gcd(a, b);
}

int main(void) {
	int num[5];
	for (int i = 0; i < 5; i++)cin >> num[i];

	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				long long muti = LCD(LCD(num[i], num[j]), num[k]);
				maxN = muti > maxN ? maxN : muti;
			}
		}
	}
	cout << maxN;

	return 0;
}

