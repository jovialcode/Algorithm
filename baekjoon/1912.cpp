#include <iostream>

using namespace std;

int n,ret;
int arr[100001];
int cache[100001];

int main() {
	cin >> n;
	for (int i = 0; i<n; i++) cin >> arr[i];
	ret = arr[0];
	for (int i = 0; i<n; i++) {
		cache[i] = arr[i];
		if (cache[i - 1] + cache[i]>cache[i]) {
			cache[i] += cache[i - 1];
		}
	}

	for (int i = 0; i<n; i++) ret = max(ret, cache[i]);
	cout << ret;
}
