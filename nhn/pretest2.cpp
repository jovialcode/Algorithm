#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int,int> pii;

int moveX[4] = {1,0,-1,0};
int moveY[4] = {0,1,0,-1};
int board[11][11];
bool visit[11][11];

int main() {
    memset(visit,0,sizeof(visit));
    vector<int> ans;
    int N; scanf("%d",&N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int num; scanf("%d",&num);
            board[i][j] = num;
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if( visit[i][j] == 1 || board[i][j] == 0) continue;
            int cnt = 0;
            queue<pii> q;
            q.push({i,j});

            while(!q.empty()){
                pii p = q.front(); q.pop();
                int curX = p.first, curY = p.second;

                if( visit[curX][curY] == 1 || board[curX][curY] == 0) continue;
                visit[curX][curY] = 1;
                cnt += 1;

                for(int i = 0; i < 4; i++){
                    int nextX = curX + moveX[i], nextY = curY + moveY[i];
                    if(nextX < 0 || nextX > N || nextY < 0 || nextY > N) continue;
                    if( visit[nextX][nextY] == 1 || board[nextX][nextY] == 0) continue;

                    q.push({nextX,nextY});
                }
            }
            ans.push_back(cnt);
        }
    }

    if(ans.size() == 0) {
        cout << "0";
        return 0;
    }

    sort(ans.begin(), ans.end());
    cout << ans.size();

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }


    return 0;
}
