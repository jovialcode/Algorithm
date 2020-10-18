#include <iostream>
#include <cstring>
#define MAX(a,b) (a>b?a:b)
using namespace std;

int board[51][51];

int main(void) {
	int N, M;
	int sol = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &board[i][j]);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <M; j++) {

			int init = board[i][j];
			int jump = M-1-j;

			while (jump > 0) {
				if (i + jump < N){
					if (init == board[i][j+jump] && init == board[i + jump][j] && init == board[i + jump][j+jump]) {
						sol = MAX(sol, jump);
					}
				}
				jump--;
			}
		}
	}
	if (sol == 0)
		printf("1\n");
	else
		printf("%d", (sol+1)*(sol+1));

	return 0;
}

