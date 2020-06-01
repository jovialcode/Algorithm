#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int fromX, fromY, toX, toY;

    while(T--){
        int N, sol = 0;
        int circle[1001][3];
        memset(circle, 0, sizeof(circle));

        cin>> fromX >> fromY>> toX>> toY;
        scanf("%d", &N);
        //입력정리
        for(int i = 0; i<N; i++){
            cin >> circle[i][0] >> circle[i][1] >> circle[i][2];
        }

        for(int i =0 ; i < N; i++){
            double d1 = sqrt(pow((fromX - circle[i][0]),2) + pow((fromY - circle[i][1]),2));
            double d2 = sqrt(pow((toX - circle[i][0]),2) + pow((toY - circle[i][1]),2));

            if(d1 > circle[i][2] && d2 < circle[i][2]) sol++;
            if(d1 < circle[i][2] && d2 > circle[i][2]) sol++;
        }
        cout << sol <<endl;
    }
    return 0;
}
