#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
int N;
string str[101],reStr[101];

int main(){
	scanf("%d", &N); getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
		reStr[i] = str[i];
	}//입력정리 

	for (int i = 0; i < N; i++) {
		reverse(reStr[i].begin(), reStr[i].end());
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (str[i] == reStr[j]) {
				cout << str[i].size() << " "<< str[i][str[i].size() / 2];
				return 0;
			}
		}
	}
}
