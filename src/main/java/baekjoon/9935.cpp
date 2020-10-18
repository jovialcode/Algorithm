#include <iostream>
#include <string>

using namespace std;
string input, bomb;
char result[1000001];
int inputLength, bombLength;

bool match(int idx) {

	for (int i = idx; i < idx + bombLength; i++) {
		if (result[i] != bomb[ i - idx ]) return false;
	}

	return true;
}
int main(){
	
	getline(cin, input);
	getline(cin, bomb);
	// 입력정리 

	inputLength = input.size();
	bombLength = bomb.size();

	int pos = 0;

	for (int i = 0; i < inputLength; i++) {
		result[pos++] = input[i];

		if (pos >= bombLength && match(pos - bombLength)) {
			pos -= bombLength;
		}
	}

	result[pos] = '\0';

	if (!pos) {
		cout << "FRULA" << endl;
	}
	else {
		cout << result;
	}

}
