#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> words) {
    int answer = 0;
    int cache = 1;

    //정렬
    sort(words.begin(), words.end());

    //앞뒤 글자 비교
    for(int i = 0; i< words.size(); i++){
        int cnt = 1;
        int maxWords = words.size() -1;
        int wordLen = words[i].size() -1;

        if(i == 0){
            for(int j = 0; j<= wordLen; j++){
                if(words[i][j] != words[i+1][j]){
                    answer += cnt;
                    cache = cnt;
                    break;
                }
                if(j == wordLen){
                    answer += cnt;
                    cache = cnt + 1;
                }
                cnt += 1;
            }
        }else if(i == maxWords ){
            answer += cache;
        }else{
            for(int j = 0; j<= wordLen; j++){
                if(words[i][j] != words[i+1][j]){
                    cache < cnt ? answer += cnt: answer += cache;
                     cache = cnt;
                    break;
                }
                if(j == wordLen){
                    answer += cnt;
                    cache = cnt + 1;
                }
                cnt += 1;
            }
        }
    }

    return answer;
}

int main() {
    //변수 선언
    int n = 0;
    vector<string> words;
    words.push_back("word");
    words.push_back("war");
    words.push_back("warrior");
    words.push_back("world");

    cout << solution(words);
    return 0;
}
