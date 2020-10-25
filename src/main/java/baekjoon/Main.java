package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int MAX_NUM = 1000003;
    public static int N, S, E, T;
    public static int[][] board;
    public static int[][][] dp;

    public static void main(String[] args) {
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

            for(int i = 0; i < N; i++){
                String str = bufferedReader.readLine();
                board[i] = Arrays.stream(str.split(""))
                        .mapToInt(num -> Integer.parseInt(num))
                        .toArray();
            }

        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void begin(){
        System.out.println(sol(S-1, E-1, T));
    }

    public static int sol(int from, int to, int cap){
        if(cap == 0) return 1;

        int left = 0;
        int right = 0;
        for (int i = 0; i < N; i++) {
            if(from != i){
                int take = board[from][i];
                if(take == 0 || cap - take < 0) continue;

                left += sol(from, i, cap - take) % MAX_NUM;
            }

            if(to != i){
                int take = board[i][to];
                if(take == 0 || cap - take < 0) continue;

                right += sol(i, to, cap - take) % MAX_NUM;
            }
        }
        return Integer.min(left, right);
    }
}
