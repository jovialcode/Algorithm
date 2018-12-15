#include <iostream>
using namespace std;

int main(){
	int H, M; scanf("%d%d", &H, &M);
	//입력정리
	int s = H * 60 * 60 + M * 60,
		ff = 45 * 60;
	s -= ff;
	if (s < 0) {
		s += 24 * 60 * 60;
	}

	int m = s / 60;
	cout << m / 60 << " " << m % 60;
}
