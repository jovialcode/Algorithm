#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int T; cin >> T;
	string str[51];
	string temp;
	int count = 0, flag = 0, lengh;
	for (int i = 0; i < T; i++)
	{
		cin >> str[i];
	}
	lengh = str[0].length();
	for (int i = 0; i < lengh; i++)
	{
		for (int j = 0; j < T; j++)
		{
			if (str[0][i] != str[j][i])
			{
				flag = 1;
			}
		}
		if (flag == 1)
			break;
		count++;
	}

	temp.assign(str[0], 0, count); temp.append(lengh - count, '?');
	cout << temp;
	
	return 0;
}