#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int N, M, ans;
string str[51];

void sol(int cnt, int learn, int idx) {
	if (idx > 26 || cnt > M) return;

	if (cnt == M) {
		int temp = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < str[i].size(); j++) {
				if ((learn & (1 << (str[i][j] - 'a'))) > 0) continue;
				
				flag = false;
				break;
				
			}
			if (flag) temp += 1;
		}
		ans = max(ans, temp);
		return ;
	}

	if ((learn & (1 << idx)) == 0) {
		sol(cnt + 1, learn | (1 << idx), idx + 1);
	}
	sol(cnt, learn, idx + 1);
}

int main(){
	scanf("%d %d", &N, &M); getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, str[i]);
	}//입력정리

	ans = 0;
	if ((M -= 5) >= 0) {

		int learn = 0;
		learn |= (1 << 0);
		learn |= (1 << 2);
		learn |= (1 << 8);
		learn |= (1 << 13);
		learn |= (1 << 19);
		sol(0, learn, 0);
	}

	cout << ans;
}
