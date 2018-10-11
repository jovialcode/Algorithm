#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, K, M;
vector<vector<int>> node(102001);
bool visit[102001];
int dist[102001];
int main() {

    memset(visit, 0, sizeof(visit));
    scanf("%d %d %d", &N, &K, &M);
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < K; j++){
            int num; scanf("%d",&num);
            node[N+i].push_back(num);
            node[num].push_back(N+i);
        }
    }
    //입력정리

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int cur  = q.front(); q.pop();
        if(cur == N) {break;}
        if(visit[cur] == 1) continue;

        visit[cur] = 1;
        for(int i = 0; i < node[cur].size(); i++){
            int next = node[cur][i];
            if(visit[next]) continue;

            dist[next] = dist[cur] + 1;
            q.push(next);
        }
    }
    if (N != 1 && dist[N] == 0) cout << -1;
    else cout << dist[N] /2 +1 << endl;
    return 0;
}
