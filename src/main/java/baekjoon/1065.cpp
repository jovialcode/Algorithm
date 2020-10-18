#include <iostream>
using namespace std;

int main(void) {
	int N, count = 0; cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		int temp = i,len = 0;
		while (temp > 0) {
			temp /= 10;
			len++;
		}

		if (len == 1 || len == 2)
			count++;
		else {
			temp = i;
			int thir = temp % 10; temp /= 10;
			int sec = temp % 10; temp /= 10;
			int fir = temp % 10; temp /= 10;
			if((sec-fir) == (thir - sec))
				count++;
		}
	}
	if (N == 1000)
		count--;
	cout << count;
	return 0;
}