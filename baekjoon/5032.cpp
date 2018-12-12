#include <iostream>
using namespace std;

int E, F, C;

int main(){
	int N = 0, sol = 0;
	scanf("%d%d%d", &E, &F, &C); //입력정리

	N = E + F;
	while (N >= C) {

		sol += (N / C);
		N = (N / C) + (N%C);

	}
	cout << sol;
}
