#include <iostream>
#include <cstring>
using namespace std;

int n,s[202][4],cnt[102][3];

int main(){
	scanf("%d", &n);
	memset(cnt, sizeof(cnt), 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &s[i][j]);
			cnt[s[i][j]][j] += 1;
		}
	}//입력정리

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			if (cnt[s[i][j]][j] == 1) {
				s[i][3] += s[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << s[i][3] << endl;
	
}
