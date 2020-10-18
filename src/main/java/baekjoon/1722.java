package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class Algo1722{
    static int N, M;
    static long K;
    static long[] factorial = new long[21];
    static boolean[] nums = new boolean[21];
    static List<Long> arr = new ArrayList<>();

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());

        if(M == 2){
            for(int i = 0; i < N; i++){
                arr.add(Long.parseLong(st.nextToken()));
            }
        }else{
            K = Long.parseLong(st.nextToken());
        }
        Arrays.fill(nums, Boolean.FALSE);
        factorialCal();
    }

    public static void print(){
        for(int i = 0; i < arr.size(); i++){
            System.out.print(arr.get(i)+ " ");
        }
    }

    public static void factorialCal(){
        factorial[0] = 1;
        factorial[1] = 1;
        for(int i = 2; i<=20; i++){
            factorial[i] = i * factorial[i-1];
        }
    }

    public static void sol1(){
        long temp = K;
        for(int i = N - 1; i >= 0; i--){
            for(int j = 1 ; j <= N; j++){
                if(nums[j]) continue;

                if(temp > factorial[i]){
                    temp -= factorial[i];
                    continue;
                }

                System.out.print(j + " ");
                nums[j] = true;
                break;
            }
        }
    }

    public static long sol2(){
        long ans = factorial[N];
        for(int i = 1; i<= N; i++){
            int cnt = (N-i);
            long num = arr.get(i-1);
            long tempCnt = factorial[N-i];

            for(int j = 1; j<=N; j++){
                if(nums[j]) continue;
                if(num == j){
                    ans -= (tempCnt * cnt);
                    nums[j] = true;
                    break;
                }
                cnt -= 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException{
        init();
        if(M == 1) sol1();
        else System.out.print(sol2());
    }
}
