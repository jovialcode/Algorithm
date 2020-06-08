/* https://www.acmicpc.net/problem/1011 */
#include <iostream>
using namespace std;

int t, x, y;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		for (int i = 1;; i++)
			if (y - x <= (long long)(i / 2)*(i / 2 + 1) + i % 2 * (i / 2 + 1)) 
			{ 
				printf("%d\n", i); 
				break; 
			}
	}
	return 0;
}
