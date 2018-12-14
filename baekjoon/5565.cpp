#include <iostream>
using namespace std;

int main(){
	int sum, sol = 0;
	scanf("%d", &sum);
	for (int i = 0; i < 9; i++) {
		int num; scanf("%d", &num);
		sol += num;
	}
	cout << sum - sol;
}
