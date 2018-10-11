#include <iostream>
#include <cstring>
#define MAX(a,b)a>b?a:b

using namespace std;
int N,M;
int board[51][51];
int dp[51][51];
bool visit[51][51];
int moveX[4] = {1, 0, -1, 0};
int moveY[4] = {0, 1, 0, -1};

int sol(int x, int y){
    if( x > N || x < 1 || y > M || y < 1 ) return 0;
    if( board[x][y] == 0 ) return 0;
    if(visit[x][y]){ puts("-1"); exit(0); }

    int &ret = dp[x][y];
    if(ret != -1 ) return ret;

    visit[x][y] = true; //cycle
    for(int i = 0; i < 4; i++){
        int step = board[x][y];
        int nextX = x + moveX[i] * step, nextY = y + moveY[i] * step;
        ret = MAX(ret, sol(nextX, nextY) + 1);
    }
    visit[x][y] = false;

    return ret ;
}

int main() {
    memset(board, 0, sizeof(board));
    memset(dp, -1, sizeof(dp));
    memset(visit, 0, sizeof(visit));

    scanf("%d%d",&N,&M);
    getchar();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            char c; scanf("%1c",&c);
            if(c == 'H') {
                board[i][j] = 0;
            }else{
                board[i][j] = c - '0';
            }
        }
        getchar();
    }

    cout << sol(1,1);
    return 0;
}
