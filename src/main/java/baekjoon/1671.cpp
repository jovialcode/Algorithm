#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
int shark[51][3];
int flow[202][202];
vector<vector<int>> edge(202);

void makeEdge(int start, int dest, int val){
    edge[start].push_back(dest);
    edge[dest].push_back(start);

    flow[start][dest] = val;
}

int main() {
    int N; scanf("%d",&N);
    int ans = N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d",&shark[i][j]);
        }
    }

    for(int i = 0; i < N; i++){
        makeEdge(2*N,i*2,2);
        makeEdge(i*2+1,2*N+1,1);

        //Who is Predator?
        for(int j = 0; j < N; j++){
            if( i == j ) continue;
            if(shark[i][0] < shark[j][0] || shark[i][1] < shark[j][1] || shark[i][2] < shark[j][2] ) continue;
            if(shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1] && shark[i][2] == shark[j][2] && i>j) continue;
            makeEdge(i*2,j*2+1,1);
        }
    }

    while(1){
        int prev[202];
        memset(prev,-1,sizeof(prev));

        queue<int> q;
        q.push(2*N);

        while(!q.empty() && prev[2*N+1] == -1){
            int cur = q.front();
            q.pop();

            for(int i = 0; i < edge[cur].size(); i++){
                int next = edge[cur][i];
                if(flow[cur][next] > 0 && prev[next] == -1){
                    q.push(next);
                    prev[next] = cur;
                }

            }
        }
        if(prev[2*N+1] == -1) break;

        for(int i = 2*N+1; i != 2*N; i = prev[i]){
            flow[i][prev[i]] += 1;
            flow[prev[i]][i] -= 1;
        }

        ans--;
    }
    cout << ans << endl;

    /*for(int i = 1; i <= N; i++) {
        for(int j = 0; j < edge[i].size(); j++){
            cout << edge[i][j] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
