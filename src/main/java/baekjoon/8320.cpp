#include <iostream>
#include <cmath>
using namespace std;

int N, r[10001];

double aliquot(int cnt) {
	double s = 0;
	for (int i = 1; i <= cnt; i++) {
		if (cnt % i == 0) s += 1;
	}
	return s;
}

int main(){
	scanf("%d", &N); //입력정리

	for (int i = 1; i <= N; i++) {
		r[i] = r[i - 1] + ceil((double)aliquot(i) / 2);
	}
	cout << r[N];
}
