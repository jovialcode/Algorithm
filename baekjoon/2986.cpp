#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	bool suc = false;
	scanf("%d", &n);

	int s = sqrt(n);
	for (i = 2; i <= s; i++) {
		if (n % i == 0) {
			suc = true;
			break;
		}
	}

	if (suc) {
		cout << n - (n / i);
	}
	else {
		cout << n - 1;
	}
}
