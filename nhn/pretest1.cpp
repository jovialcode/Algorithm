#include <iostream>
#include <vector>
using namespace std;

void move(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int ans = 0;
    char input;
    vector<int> q;

    while( (input = getchar()) != '\n'){
        if(input == ' ') continue;
        int num = input - '0', pos = -1;
        int qSize = q.size();

        // 1. 중복값 확인
        for(int i = 0 ; i < q.size(); i++){
            if(q[i] == num){ pos = i; break; }
        }

        if(pos != -1){
            if(qSize == 3){
                if(pos == 0){
                    move(q[0],q[1]);
                    move(q[1],q[2]);
                }else if( pos == 1){
                    move(q[1],q[2]);
                }
            }else if(qSize == 2){
                if(pos == 0){
                    move(q[0],q[1]);
                }
            }
        }else{
            if(qSize >=3){
                ans += 1;
                cout << q[0] << endl;
                q[0] = q[1];
                q[1] = q[2];
                q[2] = num;
            }else{
                q.push_back(num);
            }
        }
    }

    if(ans == 0){
        cout << "0";
    }
    return 0;
}
