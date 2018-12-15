#include <iostream>
#include <string>
using namespace std;

int main(){
	int strSize = 0;
	string str[5];
	for (int i = 0; i < 5; i++) {
		getline(cin, str[i]);
		strSize += str[i].size();
	}//입력정리

	int cnt = 0;
	bool anymore = false;
	while(strSize > 0){
		for (int i = 0; i < 5; i++) {
			if (str[i].size() <= cnt) 
				continue;  
			cout << str[i][cnt];
			strSize -= 1;
		}
		cnt += 1;
	}

}
