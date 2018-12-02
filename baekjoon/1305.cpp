#include <iostream>
#include <string>
#include <vector>
using namespace std;

int L;
string str;

vector<int> getPi(string a) {
	int aSize = a.size(), j = 0;
	vector<int> p(aSize,0);

	for (int i = 1; i < aSize; i++) {
		while (j > 0 && a[i] != a[j])
			j = p[j - 1];

		if (a[i] == a[j]) {
			p[i] = ++j;
		}
	}

	return p;
}

int main(){
	scanf("%d", &L); getchar();
	getline(cin, str);
	//입력정리 
	
	auto pi = getPi(str);
	cout << L - pi[L - 1];	
}
