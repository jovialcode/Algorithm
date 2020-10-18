#include <iostream>
#include <string>
#include <map>
using namespace std;
string nums;

map<string,string> m;
int main(){
	
	m["000"] = "0";
	m["001"] = "1";
	m["010"] = "2";
	m["011"] = "3";
	m["100"] = "4";
	m["101"] = "5";
	m["110"] = "6";
	m["111"] = "7";

	cin >> nums; //입력정리

	string a = "";
	int i = nums.size() % 3;
	
	if (i != 0) {
		while (i++ < 3) {
			a.push_back('0');
		}
	}
	nums = a + nums;


	for (int i = 0; i < nums.size()/3; i++) {
		string s = nums.substr(i*3, 3);
		cout << m[s];
	}
}
