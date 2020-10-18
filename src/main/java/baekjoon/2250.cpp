#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;
typedef pair<int,int> pii;

vector<pii> tree(10001);
int leftLevel[10001], rightLevel[10001];
int rows[10001];
bool visit[10001];

int childCount(int start){
    if(start == -1) return 0;

    int cnt = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int from = q.front(); q.pop();
        int left = tree[from].first, right = tree[from].second;
        if(left != -1) q.push(left);
        if(right != -1)q.push(right);
        cnt += 1;
    }

    return cnt;
}

void leftDfs(int start,int level, int pos, int way){
    int left = tree[start].first, right = tree[start].second;
    int rightCnt= childCount(right), leftCnt = childCount(left), startPos;
    way == 0 ? startPos = pos - rightCnt : startPos = pos + leftCnt;

    rows[start] = startPos;
    if(leftLevel[level] == -1) leftLevel[level] = start;
    visit[start] = 1;

    if(left != -1 && visit[left] != 1) {
        leftDfs(left, level + 1, startPos - 1, 0);
    }
    if(right != -1 && visit[right] != 1) {
        leftDfs(right, level + 1, startPos + 1, 1);
    }


}

void rightDfs(int start,int level, int cnt){
    int left = tree[start].first, right = tree[start].second;
    int rightCnt = childCount(right), lefttCnt = cnt - rightCnt;
    visit[start] = 1;

    if(rightLevel[level] == -1) rightLevel[level] = start;

    if(right != -1 && visit[right] != 1) {
        rightDfs(right, level + 1, rightCnt - 1);
    }
    if(left != -1 && visit[left] != 1) {
        rightDfs(left, level + 1, lefttCnt - 1);
    }

}

int main() {
    //입력정리
    int N; scanf("%d",&N);
    bool roots[10001] = {0,};
    int  root = 1;
    stack<pii> left, right;

    memset(leftLevel, -1, sizeof(leftLevel));
    memset(rightLevel, -1, sizeof(rightLevel));
    memset(visit,0, sizeof(visit));
    memset(rows,0, sizeof(rows));

    for (int i = 0; i< N; i++){
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        tree[node].first = left;
        tree[node].second = right;
        if(left != -1 ) roots[left] = 1;
        if(right != -1 ) roots[right] = 1;
    }
    // 입력정리
    for(int i = 1; i <=N; i++){
        if(roots[i] == 0) {
            root = i;
            break;
        }
    }

    leftDfs(root,1, N , 0);
    memset(visit,0, sizeof(visit));
    rightDfs(root,1, N);

    int anslevel = 0, ansVal = 0;

    for (int i = 1; i<= N; i++){
        int left = leftLevel[i], right = rightLevel[i];
        if(left == -1 or right == -1) break;

        if( ansVal < rows[right] - rows[left] + 1) {
            anslevel = i;
            ansVal = rows[right] - rows[left] + 1;
        }
    }
    cout << anslevel << " " <<ansVal;

    return 0;
}
