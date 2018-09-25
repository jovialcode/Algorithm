#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
vector<vector<pii>> map(10001);

pii dfs(int start){
    pii tempAns;
    int visit[10001] = {0,};
    visit[start] = 1;

    priority_queue<pii> q;
    q.push({0,start});

    while(!q.empty()){
        pii current = q.top(); q.pop();
        int curNode = current.second, curVal = current.first;

        for(int j = 0; j < map[curNode].size(); j++){
            int to = map[curNode][j].first , add = map[curNode][j].second;
            if(visit[to] == 1) {
                if(tempAns.second < curVal){
                    tempAns.second = curVal;
                    tempAns.first = curNode;
                }
                continue;
            }
            q.push({curVal + add, to});
        }
        visit[curNode] = 1;
    }

    return tempAns;
}

int main() {

    //입력정리
    int N; scanf("%d",&N);
    int ans = 0, start = 1 ;

    for(int i = 1; i < N; i++){
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
        map[from].push_back({to,val});
        map[to].push_back({from,val});
    }
    pii f = dfs(start);
    cout << dfs(f.first).second;

    return 0;
}
