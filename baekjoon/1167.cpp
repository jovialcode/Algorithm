#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

pii bfs(vector<vector<pii>> *graph, int start){
    bool visit[100001] = { 0, };
    pii ans; ans.second = 0;
    queue<pii> q;
    q.push({start,0});

    while(!q.empty()){
        pii p = q.front(); q.pop();
        int from = p.first, curVal = p.second;

        for (int i = 0; i < (*graph)[from].size(); i++){
            pii qp = (*graph)[from][i];
            int to = qp.first, addVal = qp.second;

            if(visit[to] == 1){
                if(ans.second < curVal){
                    ans.second = curVal;
                    ans.first = from;
                }
                continue;
            }
            q.push({to, curVal + addVal});
        }
        visit[from] =  1;
    }

    return ans;
}

int main() {

    int N; scanf("%d",&N);
    vector<vector<pii>> graph(100001);
    for( int i = 0; i < N; i++ ){
        int from
        ,   to
        ,   val;

        scanf("%d %d %d",&from, &to, &val);
        graph[from].push_back({to, val});

        while(scanf("%d", &to),to != -1){
            scanf("%d", &val);
            graph[from].push_back({to, val});
        }
    }
    cout << bfs(&graph,bfs(&graph,1).first).second;

    return 0;
}
