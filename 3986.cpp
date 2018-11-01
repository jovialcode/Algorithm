#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string str[101];

int main(){
	scanf("%d", &N); getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
	}//입력정리 

	int sol = 0;
	for (int i = 0; i < N; i++) {
		if (str[i].size() % 2 == 1) continue;
		int cnt = 0;
		stack<char> s;
		for (int j = 0; j < str[i].size(); j++) {
			if (s.empty()) {
				s.push(str[i][j]);
			}
			else {
				if (s.top() == str[i][j]) {
					s.pop();
					cnt += 1;
				}
				else {
					s.push(str[i][j]);
				}
			}
		}
		if (cnt == str[i].size()/2) sol += 1;
	}
	cout << sol;

}
