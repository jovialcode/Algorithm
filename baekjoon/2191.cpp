#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, S, V;
int match[301], visit[301];
double mouse[101][2], dig[101][2];
vector<vector<int>> adj(301);

bool dfs(int start) {
	if (visit[start]) return false;
	visit[start] = 1;

	for (int next : adj[start]) {
		if (match[next] == -1 || dfs(match[next])) {
			match[next] = start;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d%d%d", &N, &M, &S, &V);

	for (int i = 1; i <= N; i++) 
		scanf("%lf %lf", &mouse[i][0], &mouse[i][1]);

	for (int i = 1; i <= M; i++) 
		scanf("%lf %lf", &dig[i][0], &dig[i][1]);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			double dist = sqrt(pow(abs(dig[j][0] - mouse[i][0]),2.0) + pow(abs(dig[j][1] - mouse[i][1]),2.0));
			if (dist <= S * V) {
				adj[i * 2].push_back( 2*j + 1);
			}
		}
	}//입력 정리 및 간선정리
	
	memset(match, -1, sizeof(match));

	int sol = 0;
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		if(dfs(i * 2)) sol += 1;
	}

	cout << N - sol;
}

