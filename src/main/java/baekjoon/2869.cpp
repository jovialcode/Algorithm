#include <iostream>
using namespace std;

int main(void)
{
	long long int A, B, V; cin >> A >> B >> V;
	if ((V - A) % (A - B))
		cout << ((V - A) / (A - B)) + 2;
	else
		cout << ((V - A) / (A - B))+1;
	return 0;
}
