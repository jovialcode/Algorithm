#include <iostream>
#include <cmath>
#define MIN(a,b)(a>b?b:a)
#define DIS(a,b)(abs(a-b))
using namespace std;

int main(void) {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int minValue = 9876543;

	minValue = MIN(minValue, DIS(x, 0));
	minValue = MIN(minValue, DIS(y, 0));
	minValue = MIN(minValue, DIS(x, w));
	minValue = MIN(minValue, DIS(y, h));
	cout << minValue;

	return 0;
}