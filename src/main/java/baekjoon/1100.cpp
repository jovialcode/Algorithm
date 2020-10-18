#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		string str; getline(cin, str);
		for (int j = 0; j < 8; j++) 
			if (((i + j) % 2 == 0) && str[j] == 'F')
				cnt++;
	}
		
	cout << cnt;

	return 0;
}