#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int C;
int moveX[5] = {1,1,1,0,0};
int moveY[5] = {1,0,-1,-1,1};

int main(){
	scanf("%d", &C);

	while (C--) {
		
		int N, M;
		int dp[11][11] = {0,};
		char map[11][11];

		scanf("%d %d", &N, &M); getchar();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1c", &map[i][j]);
			}
			getchar();
		}
		//입력정리



	}
	
    
}
