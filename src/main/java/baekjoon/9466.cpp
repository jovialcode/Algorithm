#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;

int N, cnt;
int dfsN[MAX];
bool visited[MAX];
bool done[MAX];

void dfs(int here)
{
	visited[here] = true;
	int next = dfsN[here];
	if (!visited[next])
		dfs(next);

	else if (!done[next])
	{
		for (int i = next; i != here; i = dfsN[i])
			cnt++;
		cnt++;
	}
	done[here] = true;
}

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(visited, false, sizeof(visited));
		memset(done, false, sizeof(done));
		cin >> N;

		for (int j = 1; j <= N; j++)
			cin >> dfsN[j];

		cnt = 0;
		for (int j = 1; j <= N; j++)
			if (!visited[j])
				dfs(j);

		cout << N - cnt << endl;
	}
	return 0;
}
