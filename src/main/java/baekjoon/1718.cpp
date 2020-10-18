#include <iostream>
#include <string>

using namespace std;
int sN, cN;
int main(){
	string str, cipher;
	getline(cin, str);
	getline(cin, cipher);
	sN = str.size();
	cN = cipher.size();
	//입력정리

	if (sN > cN) {
		int times = sN / cN;
		string append = "";
		while (times--) append += cipher;
		cipher += append;
	}

	string sol = "";
	for (int i = 0; i < sN; i++) {
		if (str[i] == ' ') { sol.push_back(' '); continue; }
		int cPos = cipher[i] - '96';
		int sPos = str[i] - '96';

		if (cPos >= sPos) sPos += 26;
		sol.push_back(sPos - cPos + 96);
	}
	cout << sol;

}
