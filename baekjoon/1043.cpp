#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M, T;
int know[51];
int visit[51];
vector<vector<int>> party;
vector<vector<int>> people;

int main() {

    scanf("%d %d %d",&N, &M, &T);
    people.resize(62);
    party.resize(62);
    memset(visit, 0 , sizeof(visit));

    for ( int i = 0; i < T; i++){
        scanf("%d", &know[i]);
    }

    for ( int i = 1; i <= M; i++){
        int k; scanf("%d",&k);
        for ( int j = 0; j < k; j++){
            int invite;
            scanf("%d",&invite);
            party[i].push_back(invite);
            people[invite].push_back(i);
        }
    }// 입력정리

    queue<int> q;
    for(int i = 0; i < T; i++){
        int k = know[i];
        for(int j = 0; j < people[k].size(); j++){
            q.push(people[k][j]);
        }
    }

    while(!q.empty()){
        int start = q.front(); q.pop();
        if(visit[start] > 0) continue;

        visit[start] = 1;

        for(int i = 0; i < party[start].size(); i++){
            int k = party[start][i];

            for(int j = 0; j < people[k].size(); j++){
                int party = people[k][j];
                if(visit[party]) continue;
                q.push(party);
            }
        }
    }
    int sol = 0;
    for(int i = 1; i <= M; i++){
        if(visit[i] >= 1) sol++;
    }
    cout << M - sol;

    return 0;
}
