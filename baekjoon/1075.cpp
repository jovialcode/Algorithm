#include <iostream>
using namespace std;

int main(void)
{
	long long int N; cin >> N;
	int F; cin >> F;


	for (int i = 0; i <= 9; i++)
	{
		N /= 100;
		N *= 100;
		N += i;
		if (N%F == 0){
			cout << '0' << i << endl; return 0;
		}
	}
	for (int i = 10; i <= 99; i++)
	{
		N /= 100;
		N *= 100;
		N += i;
		if (N%F == 0) {
			cout << i << endl;return 0;
		}
	}	
	return 0;
}