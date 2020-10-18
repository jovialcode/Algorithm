#include <iostream>
#include <vector>

using namespace std;

int N, degree[1002], adj[1002][1002];

void dfs(int from) {
	for (int to = 1; to <= N; to++) {
		while (adj[from][to]) {
			adj[from][to]--;
			adj[to][from]--;
			dfs(to);
		}
	}
	printf("%d ", from);
}


int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &adj[i][j]);
			degree[i] += adj[i][j];
		}
	}// 입력정리

	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2 == 1) {
			cout << -1 << endl;
			return 0;
		}
	}// 차수가 홀수면 오일러 회로 없음

	dfs(1);


}
