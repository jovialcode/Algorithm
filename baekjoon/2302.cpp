#include <iostream>
using namespace std;

long long int S[41] = { 0 };
int vipseat[41];

int main(void)
{
	int N; cin >> N;
	int vip; cin >> vip;
	long long int cnt = 1;
	for (int i = 1; i <= vip; i++)
	{
		cin >> vipseat[i];
	}
	vipseat[0] = 0;
	vipseat[vip + 1] = N+1;
	S[0] = 1;S[1] = 1;
	for (int i = 2; i <= N; i++)
		S[i] = S[i - 1] + S[i - 2];

	for (int i = 0; i <= vip; i++)
	{
		cnt *= S[vipseat[i + 1] - vipseat[i]-1];
	}
	cout << cnt;
	return 0;
}
