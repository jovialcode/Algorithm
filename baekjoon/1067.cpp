#include <iostream>
#include <list>
#define MAX(a,b)(a>b?a:b)
using namespace std;

list<int>X;
list<int>Y;
int main(void) {
	int N; cin >> N;
	int Xcnt=0;
	long long maxVal=0;
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		X.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		int temp; scanf("%d", &temp);
		Y.push_back(temp);
	}
	while (Xcnt != X.size()) {
		int Ycnt = 0;
		int xTemp;
		while (Ycnt != Y.size()) {
			long long tempSum = 0;
			int yTemp;
			for (list<int>::iterator ix = X.begin(), iy = Y.begin(); ix != X.end(), iy != Y.end(); ++ix, ++iy) {
				tempSum += ((*ix)*(*iy));
			}
			maxVal = MAX(maxVal, tempSum);
			yTemp = Y.front(); Y.pop_front();
			Y.push_back(yTemp);
			Ycnt++;
		}
		xTemp = X.front(); X.pop_front();
		X.push_back(xTemp);
		Xcnt++;
	}
	cout << maxVal;
	return 0;
}
