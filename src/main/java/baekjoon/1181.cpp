#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string a, string b);
bool compare_word(string a, string b);

int main(void)
{

	int N; cin >> N;
	char **text = new char*[N];
	string check= "123";
	for (int i = 0; i < N; i++)
	{
		text[i] = new char[51];
		cin >> text[i];
		for (int j = 0; j < i; j++)
		{
			if (text[j] == text[i])
				i--;
		}
	}//동적 문자열 배열 할당과 문자들의 길이

	vector<string> myvector(text, text + N);
	vector<string>::iterator it;

	sort(myvector.begin(), myvector.end(), compare);
	for (it = myvector.begin(); it != myvector.end(); ++it)
	{
		if ((check.compare(*it) == 0))
		{
			continue;
		}
		else
		{
			cout << *it << endl;
			check.clear();
			check.append(*it);
		}
	}
		
	for (int i = 0; i < N; i++)
	{
		delete[] text[i];
	}
	delete[] text;
	return 0;
}

bool compare(string a, string b)
{
	if (a.length() == b.length())
		return compare_word(a, b);
	return (a.length() < b.length());
}

bool compare_word(string a, string b)
{
	return (a.compare(b) < 0);
}