#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, pattern;

int main() {
	getline(cin, str);
	getline(cin, pattern);
	//입력정리

	int ans = 0;
	int patternSize = pattern.size(),
		strSize = str.size();

	for (int i = 0; i < strSize; i++) {

		int temp = 0, j = i;

		while (j < strSize && (j = str.find(pattern, j)) >= 0) {
			j += patternSize;
			temp += 1;
		}
		ans = max(ans, temp);
	}
	cout << ans;
}
