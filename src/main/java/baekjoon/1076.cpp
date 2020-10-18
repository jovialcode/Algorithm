#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<string, int> color;

int main(void) {
	long long sum = 0;
	color["black"] = 0;
	color["brown"] = 1;
	color["red"] = 2;
	color["orange"] = 3;
	color["yellow"] = 4;
	color["green"] = 5;
	color["blue"] = 6;
	color["violet"] = 7;
	color["grey"] = 8;
	color["white"] = 9;

	string a, b, c;
	cin >> a >> b >> c;
	sum += (color[a] * 10 + color[b])*(long long)pow(10, color[c]);
	cout << sum;
	return 0;
}
