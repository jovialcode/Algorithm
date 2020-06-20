/*
 * Description :
 *   url : https://www.acmicpc.net/problem/2662
 *   type : DP
 * */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo2662 {
    static int N, M;
    static final int INF = 987654321;
    static int[][] nums;
    static int[][] dp;
    static int[][] ways;

    public static void inputVariable(){
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try{
            StringTokenizer st = new StringTokenizer(br.readLine());

            N = Integer.parseInt(st.nextToken()); // 투자 금액
            M = Integer.parseInt(st.nextToken()); // 기업 수

            nums = new int[N+1][M+1];
            dp = new int[N+1][M+1];
            ways = new int[N+1][M+1];

            for (int i = 1; i <= N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j <= M; j++) {
                    nums[i][j] = Integer.parseInt(st.nextToken());
                    dp[i][j] = -1;
                }
            }
        }catch(IOException e){
            System.out.println(e);
        }
    }

    public static int solving(int amount, int com){
        if(amount == 0) return 0;

        if(amount < 0) return -INF;
        if(com > M) return -INF;

        int ret = dp[amount][com];
        if(ret != -1) return ret;

        for(int i = 0; i <= amount; i++){
            int temp = solving(amount - i , com + 1) + nums[i][com];
            if( ret < temp ){
                ret = temp;
                ways[amount][com] = i;
            }
        }
        return dp[amount][com] = ret;
    }

    public static void printing(){
        int remain = N;
        for (int i = 1; i <= M; i++) {
            System.out.print(ways[remain][i] + " ");
            remain -= ways[remain][i];
        }
    }

    public static void main(String[] args){
        inputVariable();
        System.out.println(solving(N, 1));
        printing();
    }
}
