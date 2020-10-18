#include <iostream>
#include <string>
using namespace std;

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		int N, aS = 0; scanf("%d", &N);
		double bS = 0;
		for (int i = 0; i < N; i++) {
			int a; double b;
			scanf("%d %lf", &a, &b);
			//입력정리

			aS += a;
			bS += a*b;
		}
		printf("%d %0.1f\n", aS, bS/aS);
	}
}
