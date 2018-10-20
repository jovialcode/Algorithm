#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10001;

int V, E, cnt, SN;
int dfsn[MAX], sn[MAX];
bool finished[MAX]; 
stack<int> S;

vector<int> adj[MAX];
vector<vector<int>> SCC;

int DFS(int curr) {
	dfsn[curr] = ++cnt;
	S.push(curr); 

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0) result = min(result, DFS(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}
	if (result == dfsn[curr]) {
		vector<int> currSCC;
		while (1) {
			int t = S.top();
			S.pop();
			currSCC.push_back(t);
			finished[t] = true;
			sn[t] = SN;
			if (t == curr) break;
		}
		sort(currSCC.begin(), currSCC.end());
		SCC.push_back(currSCC);
		SN++;
	}
	return result;
}

int main() {
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		adj[A].push_back(B);
	}//입력정리

	cnt = 1;
	memset(dfsn, 0, sizeof(dfsn));

	for (int i = 1; i <= V; i++)
		if (dfsn[i] == 0) DFS(i);

	sort(SCC.begin(), SCC.end());
	printf("%d\n", SN);
	for (auto& currSCC : SCC) {
		for (int curr : currSCC)
			printf("%d ", curr);
		puts("-1");
	}
}

