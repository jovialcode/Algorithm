#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int N, pos, Lsize, Rsize;
string str[101], pattern, patternL, patternR;

int main(){
	scanf("%d", &N); getchar();
	getline(cin, pattern);
	for (int i = 0; i < N; i++) getline(cin, str[i]);
	//입력정리

	pos = pattern.find('*');
	patternL = pattern.substr(0, pos);
	patternR = pattern.substr(pos + 1);
	
	Lsize = patternL.size();
	Rsize = patternR.size(); 
	//정리 

	for (int i = 0; i < N; i++) {
		int findL = str[i].find(patternL,0),
			findR = str[i].rfind(patternR);

		if (Lsize + Rsize <= str[i].size() && findL == 0 && findR == (str[i].size() - Rsize)) {
			cout << "DA" << endl;
		}
		else {
			cout << "NE" << endl;
		}
	}
}
