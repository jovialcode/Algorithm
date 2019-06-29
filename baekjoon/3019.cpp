#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int C, P;
int board[101];

int sol(string h) {
	int cnt = 0;
	int width = h.size();
	vector<int> addBlock;
	for (int i = 0; i < width; i++) 
		addBlock.push_back(h[i] - '0');

	for (int i = 0; i <= C - width; i++) {
		bool done = true;
		for (int j = 0; j < width - 1; j++) {
			if(board[i + j] - board[i + j + 1] != addBlock[j] - addBlock[j + 1]){
				done = false;
				break;
			}
		}
		if (done) cnt++;
	}

	return cnt;
}

int main(){
	scanf("%d %d", &C, &P);

	for (int i = 0; i < C; i++) {
		scanf("%d", &board[i]);
	}
	//입력정리
	
	int ans = 0;
	if (P == 1) {
		ans += sol("0");
		ans += sol ("0000");
	}
	else if (P == 2) {
		ans += sol("00");
	}
	else if (P == 3) {
		ans += sol("001");
		ans += sol("10");
	}
	else if (P == 4) {
		ans += sol("100");
		ans += sol("01");
	}
	else if (P == 5) {
		ans += sol("000");
		ans += sol("01");
		ans += sol("10");
		ans += sol("101");
	}
	else if (P == 6) {
		ans += sol("000");
		ans += sol("20");
		ans += sol("011");
		ans += sol("00");
	}
	else {
		ans += sol("000");
		ans += sol("00");
		ans += sol("110");
		ans += sol("02");
	}
	cout << ans;
}
