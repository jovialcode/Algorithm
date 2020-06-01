/*
 * Description :
 *   url : https://www.acmicpc.net/problem/5549
 *   type : Implementation
 * */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class algo_5549 {
    static int N, M, K;
    static String[] board;
    static int[][][] dp;

    static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken()); // 지도 크키 가로
        N = Integer.parseInt(st.nextToken()); // 지도 크기 세로

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken()); // 구역 숫자

        board = new String[M];
        dp = new int[3][M+1][N+1];

        for(int i = 0; i < M; i++){
            board[i] = br.readLine();
        }

        //구간 합 구하기
        preSum();

        //query
        for(int i = 0; i < K; i++){
            st = new StringTokenizer(br.readLine());
            int fromX = Integer.parseInt(st.nextToken());
            int fromY = Integer.parseInt(st.nextToken());
            int toX = Integer.parseInt(st.nextToken());
            int toY = Integer.parseInt(st.nextToken());

            print(sol(fromX, fromY, toX , toY));
        }
    }

    public static void preSum(){
        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                char c = board[i-1].charAt(j-1);
                switch (c){
                    case 'J': {
                        dp[0][i][j] = dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1] + 1;
                        dp[1][i][j] = dp[1][i-1][j] + dp[1][i][j-1] - dp[1][i-1][j-1];
                        dp[2][i][j] = dp[2][i-1][j] + dp[2][i][j-1] - dp[2][i-1][j-1];
                        break;
                    }
                    case 'O': {
                        dp[0][i][j] = dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
                        dp[1][i][j] = dp[1][i-1][j] + dp[1][i][j-1] - dp[1][i-1][j-1] + 1;
                        dp[2][i][j] = dp[2][i-1][j] + dp[2][i][j-1] - dp[2][i-1][j-1];
                        break;
                    }
                    case 'I': {
                        dp[0][i][j] = dp[0][i-1][j] + dp[0][i][j-1] - dp[0][i-1][j-1];
                        dp[1][i][j] = dp[1][i-1][j] + dp[1][i][j-1] - dp[1][i-1][j-1];
                        dp[2][i][j] = dp[2][i-1][j] + dp[2][i][j-1] - dp[2][i-1][j-1] + 1;
                        break;
                    }
                }
            }
        }
    }

    public static String sol(int fromX, int fromY, int toX, int toY) {
        int ansJ = dp[0][toX][toY] - dp[0][toX][fromY-1] - dp[0][fromX-1][toY] + dp[0][fromX-1][fromY-1];
        int ansO = dp[1][toX][toY] - dp[1][toX][fromY-1] - dp[1][fromX-1][toY] + dp[1][fromX-1][fromY-1];
        int ansI = dp[2][toX][toY] - dp[2][toX][fromY-1] - dp[2][fromX-1][toY] + dp[2][fromX-1][fromY-1];
        return ansJ + " " + ansO + " " + ansI;
    }

    public static void print(String val){
        System.out.println(val);
    }

    public static void main(String[] args) throws IOException{
        init();
    }
}
