#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000001;
int N, M, h, ts, from,to;
vector<int> num(100001);
vector<int> minTree(262145);
vector<int> maxTree(262145);

int initMin(int node, int from, int to) {
	
	if (from == to) {
		return minTree[node] = num[from];
	}
	int mid = (from + to) / 2;

	return minTree[node] = min(initMin(node * 2, from, mid),initMin(node * 2 + 1, mid + 1, to));
}

int initMax(int node, int from, int to) {

	if (from == to) {
		return maxTree[node] = num[from];
	}
	int mid = (from + to) / 2;

	return maxTree[node] = max(initMax(node * 2, from, mid), initMax(node * 2 + 1, mid + 1, to));
}

int findMin(int node, int a, int b) {
	if (b < from || a > to) return INF;
	if (from <= a && b <= to) return minTree[node];

	int mid = (a + b) / 2;
	return min(findMin(node * 2, a, mid), findMin(node * 2 + 1, mid + 1, b));
}

int findMax(int node, int a, int b) {
	if (b < from || a > to) return -1;
	if (from <= a && b <= to) return maxTree[node];

	int mid = (a + b) / 2;
	return max(findMax(node * 2, a, mid), findMax(node * 2 + 1, mid + 1, b));
}

int main(){
	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);


	initMin(1, 0, N - 1);
	initMax(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		scanf("%d%d", &from, &to);
		from -= 1; to -= 1;
		printf("%d %d\n",findMin(1, 0, N - 1),findMax(1, 0, N - 1));
	}
}
