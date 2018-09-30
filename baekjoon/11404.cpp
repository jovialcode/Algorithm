#include <iostream>
#define INF 100001
using namespace std;


int main(void) {
    int n, m;
    int city[101][101];

    for(int i = 1; i<= 100; i++)
        for (int j = 1; j <= 100; j++)
            city[i][j] = INF;

    scanf("%d %d", &n, &m);
    while (m--) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        if(city[from][to] > cost)
            city[from][to] = cost;
    }//입력처리

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ( i == j || i == k || k == j) continue;
                if (city[i][k] == INF || city[k][j] == INF ) continue;
                if (city[i][j] > city[i][k] + city[k][j]) city[i][j] = city[i][k] + city[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == INF) cout << "0" << " ";
            else cout << city[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
