#include <iostream>
#include <string>
using namespace std;

int main(){
	string num1, oper, num2;
	getline(cin, num1); getline(cin, oper); getline(cin, num2);
	//입력정리
	
	int num1Sqaure = num1.size() - 1,
		num2Sqaure = num2.size() - 1;

	if (oper == "*") {
		int s = num1Sqaure + num2Sqaure;
		printf("1");
		while (s--) {
			printf("0");
		}
	}
	else {
		if (num1Sqaure > num2Sqaure) {
			num1[num1Sqaure - num2Sqaure] = '1';
			cout << num1;
		}
		else if (num1Sqaure < num2Sqaure) {
			num2[num2Sqaure - num1Sqaure] = '1';
			cout << num2;
		}
		else {
			num1[0] = '2';
			cout << num1;
		}
	}
}
