#include <iostream>
#include <string>
using namespace std;

#define INF 987654321
#define min(a,b)(a<b?a:b)

int main() {
	int ret = INF;
	string str1, str2;
	cin >> str1 >> str2;
	int diff = str2.length() - str1.length();
	for (int i = 0; i <= diff; i++) {
		int tmp = 0;
		for (int j = 0; j<str1.length(); j++) {
			if (str1[j] != str2[j + diff])
				tmp++;
		}
		ret = min(ret, tmp);
	}
	cout << ret << endl;
	return 0;
}
