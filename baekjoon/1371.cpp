#include <iostream>
#include <string>
#define MAX(a,b)(a>b?a:b)
using namespace std;

int alpha[27] = { 0 };
int main(void) {
	string str;
	int cnt = 0;
	while (getline(cin, str)) {
		if (cin.bad())
			break;
		for (int i = 0; i < str.size(); i++)
			alpha[str[i]-'a']++;
	}

	for (int i = 0; i < 27; i++)
		cnt = MAX(cnt, alpha[i]);
	for (int i = 0; i < 27; i++)
		if (alpha[i] == cnt)
			printf("%c",'a' + i);
	return 0;
}
