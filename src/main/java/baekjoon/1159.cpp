#include <iostream>
#include <string>
using namespace std;

int alpha[26] = { 0 };
string name[151];
int main(void) {
	int N; cin >> N; cin.clear(); cin.ignore();
	for (int i = 0; i < N; i++)
		cin >> name[i];
	for (int i = 0; i < N; i++) {
		alpha[name[i][0] - 'a']++;
	}
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] >= 5) {
			printf("%c", (i + 'a'));
			cnt++;
		}
	}
	if (cnt == 0)
		cout << "PREDAJA";
	return 0;
}