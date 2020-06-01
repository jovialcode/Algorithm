#include <iostream>
using namespace std;

int main(void)
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b; cin >> a >> b;
		int mis = a % 10;
		if (mis == 1 || mis == 5 || mis == 6 || mis == 10)
		{
			cout << mis << endl;
		}
		else if (mis == 4 || mis == 9)
		{
			if (b % 2 == 0)
				cout << (mis*mis) % 10 << endl;
			else
				cout << mis << endl;
		}
		else if (mis == 0)
		{
			cout << "10" << endl;
		}
		else {
			switch (b % 4) {
			case 1: cout << mis << endl; break;
			case 2: cout << (mis*mis) % 10 << endl; break;
			case 3: cout << (mis*mis*mis) % 10 << endl; break;
			case 0: cout << (mis*mis*mis*mis) % 10 << endl; break;
			}
		}

	}
	return 0;
}