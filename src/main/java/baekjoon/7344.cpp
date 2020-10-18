#include <stdc++.h>
using namespace std;
using P = pair<int, int>;

vector<P> task;
bool visit[5001];

int main(){
	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		//입력정리
		task.clear();
		memset(visit, 0, sizeof(visit));

		for (int k = 0; k < N; k++) {
			int i, w; scanf("%d%d", &i, &w);
			task.push_back({i,w});
		}

		sort(task.begin(), task.end());

		int sol = 0;
		for (int i = 0; i < task.size(); i++) {
			if (!visit[i]) {

				P cur = task[i];
				int last = cur.second;
				sol += 1;

				for (int j = i + 1; j < task.size(); j++) {
					P next = task[j];
					if (!visit[j] && last <= next.second) {
						visit[j] = 1;
						last = next.second;
					}
				}
			}
		}

		cout << sol <<endl;
	}
}
