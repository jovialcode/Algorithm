package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * input
 * 3 1 3 5
 * 012
 * 201
 * 120
 * */
public class Algo1533 {
    public static int MAX_NUM = 1000003;
    public static int N, S, E, T;
    public static int[][] board;
    public static int[][] dp;

    public Algo1533() {
        input();
        begin();
    }

    public static void input(){
        try(InputStreamReader is = new InputStreamReader(System.in);
            BufferedReader bufferedReader = new BufferedReader(is);
        ){
            StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
            N = Integer.parseInt(st.nextToken());
            S = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            board = new int[N][N];
            dp = new int[N][N];

            for(int i = 0; i < N; i++){
                String str = bufferedReader.readLine();
                board[i] = Arrays.stream(str.split(""))
                        .mapToInt(num -> Integer.parseInt(num))
                        .toArray();
            }

//            for (int i = 0; i < N ; i++) {
//                for (int j = 0; j <N ; j++) {
//                    dp[i][j]  = -1;
//                }
//            }

        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void begin(){
        System.out.println(sol(S-1, E-1, T));
    }

    public static int sol(int from, int to, int cap){
        if(to == E - 1 && cap == 0) return 1;

        for (int i = 0; i < N; i++) {
            if(i == to) continue;

            int take = board[to][i];
            if(cap >= take) {
                dp[from][to] += (sol(from, i, cap - take) + sol(i, to, cap - take)) % MAX_NUM;
            }
        }
        return dp[from][to];
    }
}
