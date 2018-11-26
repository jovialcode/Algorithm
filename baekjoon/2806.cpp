#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, a[1000005],b[1000005];
string s;

int main(){
	scanf("%d", &N); getchar();
	getline(cin, s);
	//입력정리
	
	if (s[0] == 'A') {
		a[0] = 0;
		b[0] = 1;
	}
	else {
		a[0] = 1;
		b[0] = 0;
	}
	
	for (int i = 1; i < N; i++) {
		if (s[i] == 'A') {
			a[i] = a[i - 1];
			b[i] = 1 + min(a[i - 1], b[i - 1]);
		}
		else {
			b[i] = b[i - 1];
			a[i] = 1 + min(a[i - 1], b[i - 1]);
		}
	}

	cout << a[N - 1];
}
