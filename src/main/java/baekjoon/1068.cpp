#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {

    int N
    , leaves = 0
    , delNode
    , start;

    scanf("%d", &N);
    vector<vector<int>> tree(51);


    for(int i = 0; i < N; i++){
        int from = i, to; scanf("%d",&to);
        if( to == -1 ) {
            start = i;
            continue;
        }
        tree[to].push_back(from);
    }

    scanf("%d",&delNode);

    if( start != delNode) {
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int from = q.front();q.pop();
            if (tree[from].size() == 0) leaves++;
            for (int i = 0; i < tree[from].size(); i++) {
                int to = tree[from][i];
                if (to == delNode) {
                    if (tree[from].size() == 1) leaves++;
                    continue;
                }
                q.push(to);
            }
        }
    }

    cout << leaves << endl;

    return 0;
}
