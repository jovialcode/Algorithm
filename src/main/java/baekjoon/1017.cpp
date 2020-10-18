#include "pch.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int N, first, second;
int nums[51],leftVisit[102],rightVisit[102];
bool primeNum[2001];

void findPrimeNum() {
	
	for (int i = 2; i <= sqrt(2000); i++) {
		if (primeNum[i]) {
			for (int j = i * i; j <= 2000; j += i) {
				primeNum[j] = false;
			}
		}
	}
	return ;
}

bool dfs(int from) {
	if (leftVisit[from]) return false;

	leftVisit[from] = 1;

	for (int to = 2; to <= N; to++) {
		if ( to == second || !primeNum[nums[from]+nums[to]]) continue;

		if (!rightVisit[to] || dfs(rightVisit[to])) {
			rightVisit[to] = from;
			rightVisit[from] = to;
			return true;
		}
	}
	return false;
}

int main(){
	memset(primeNum, true, sizeof(primeNum));
	findPrimeNum(); //소수정리

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
	}
	//입력정리
	
	
	priority_queue<int, vector<int>, greater<int> > q;
	first = 1;
	for (int i = 2; i <= N; i++) {
		second = i;
		if (!primeNum[nums[first] + nums[second]]) continue;

		memset(rightVisit, 0, sizeof(rightVisit));
		
		int match = 1;
		for (int j = 2; j <= N; j++) {
			if (j == second || rightVisit[j]) continue;

			memset(leftVisit, 0, sizeof(leftVisit));
			rightVisit[1] = i; rightVisit[i] = 1;
			leftVisit[1] = 1; leftVisit[i] = 1;

			if (dfs(j)) match++;
		}
		if (match * 2 == N) {
			q.push(nums[second]);
		}
	}

	if (q.size() == 0) {
		q.push(-1);
	}
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}
