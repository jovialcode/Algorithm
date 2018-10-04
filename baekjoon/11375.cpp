#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<vector<int>> node(1001);
int shed[1001], visit[1001];
int dfs(int cur){
    if(visit[cur]) return 0;

    visit[cur] = 1;
    for(int next : node[cur]){
        if(!shed[next] || dfs(shed[next])){
            shed[next] = cur;
            return 1;
        }
    }
    return 0;
}

int main() {

    int N, M; scanf("%d %d",&N, &M);
    int ans = 0;
    memset(shed, 0, sizeof(shed));

    for(int i = 1; i <= N; i++){
        int h; scanf("%d",&h);
        for(int j = 1; j <= h; j++){
            int house; scanf("%d", &house);
            node[i].push_back(house);
        }
    }

    //입력 정리

    for(int i = 1; i <= N; i++){
        memset(visit, 0, sizeof(visit));
        if(dfs(i)){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
