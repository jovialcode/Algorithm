#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX(a,b)a>b?a:b

using namespace std;
typedef pair<int,int> pii;
int N,M;
int visit[20001];
vector<vector<int>> map;
vector<vector<int>> ans;


int main() {
    int sol = 0;
    scanf("%d %d",&N, &M);
    map.resize(N+2);
    ans.resize(N+2);
    memset(visit,0,sizeof(visit));
    for(int i = 0; i < M; i++){
        int from, to; scanf("%d %d",&from, &to);
        map[from].push_back(to);
        map[to].push_back(from);
    }

    //입력정리
    queue<pii> q;
    q.push({1,0});

    while(!q.empty()){
        pii cur = q.front(); q.pop();
        int from = cur.first, cnt = cur.second;

        if(visit[from]) continue;
        visit[from] = 1;

        sol = MAX(sol,cnt);
        ans[cnt].push_back(from);

        for(int i = 0; i < map[from].size(); i++){
            int to = map[from][i];
            if(visit[to]) continue;
            q.push({to,cnt+1});
        }
    }

    sort(ans[sol].begin(), ans[sol].end());

    cout << ans[sol][0] << " " << sol << " " << ans[sol].size();

    return 0;
}
