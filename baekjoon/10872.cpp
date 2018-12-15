#include <iostream>

using namespace std;
long long f[13];

int main(){
	f[0] = f[1] = 1;
	for (int i = 2; i <= 12; i++)
		f[i] = f[i - 1] * i;

	int num; scanf("%d", &num);
	cout << f[num];
}
