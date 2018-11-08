#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A, B;

int main(){
	cin >> A >> B;
	//입력정리

	int posB = 987654321, posA = 987654321;
	for (int i = 0; i < 26; i++) {
		char c = 65 + i;

		int aPos = A.find(c),
			bPos = B.find(c);

		if(aPos != -1 && bPos != -1)
			if (posA > aPos) {
				posB = bPos;
				posA = aPos;
			}
		}
	
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < A.size(); j++) {

			if (i == posB) {
				cout << A[j];
			}
			else {
				if (j == posA) { 
					cout << B[i]; 
}
				else { cout << "."; }
			}
		}
		cout << endl;
	}
}
