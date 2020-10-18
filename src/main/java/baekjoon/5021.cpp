#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

//001. 변수 정리
struct node {
	string _name;
	vector<node> _child;

	node(){}

	node(string name) {
		this->_name = name;
	}
};

int N, M;
string lines[51][3], insist[51];
node king;

//002. 함수 정의
void input(); 
void dfs(node& parent); // parents to children 트리 만들기
double sol(string target, node& start, int depth);


int main(){
	double maxV = 0;
	string ans = "";
	input();
	dfs(king);
	
	for (int i = 0; i < M; i++) {
		double val = sol(insist[i], king, 0);
		if (maxV < val) {
			maxV = val;
			ans = insist[i];
		}
	}

	cout << ans;
}

void input() {
	string str;
	scanf("%d %d", &N, &M); getchar();
	cin >> str;

	king._name = str;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> lines[i][j];

	for (int i = 0; i < M; i++)
		cin >> insist[i];
}

double sol(string target, node &start, int depth) {
	double ret = 0;

	if (start._name == target) return ret += pow(0.5, depth);
	else {
		for (int i = 0; i < start._child.size(); i++) {
			ret += sol(target, start._child[i], depth + 1);
		}
	}
	return ret;
}

void dfs(node& parent) {
	int j = 0;
	for (int i = 0; i < N; i++) {

		if (lines[i][1] == parent._name || lines[i][2] == parent._name) {
			parent._child.push_back(node(lines[i][0]));
			dfs(parent._child[j]);
			j += 1;
		}
	}
}
