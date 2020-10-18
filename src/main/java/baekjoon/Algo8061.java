package baekjoon;/*
 * Description :
 *   url : https://www.acmicpc.net/problem/8061
 *   type : BFS
 * */

import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Algo8061 {
    static int INF = 999999;
    static int N, M;
    static int[] moveX = new int[] {-1,1,0,0};
    static int[] moveY = new int[] {0,0,-1,1};
    static String[] board;
    static int[][] ans;

    static void initializng() {
        ans = new int[N][M];
        board = new String[N];
    }

    public static void inputVariable() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken()); // ���� ũŰ ����
        M = Integer.parseInt(st.nextToken()); // ���� ũ�� ����

        //�Է� ���� ���� ���� init
        initializng();

        for (int i = 0; i < N; i++) board[i] = br.readLine();
    }

    public static void preProcessing(){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char c = board[i].charAt(j);
                if(c == '1') ans[i][j] = 0;
                else ans[i][j] = INF;
            }
        }
    }

    public static void checking(int x, int y){
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(x,y));

        while(!q.isEmpty()){
            Pair<Integer, Integer> p = q.poll();
            int nowX = p.getKey().intValue();
            int nowY = p.getValue().intValue();
            int value = ans[nowX][nowY];

            for (int i = 0; i < 4; i++) {
                int nextX = nowX + moveX[i];
                int nextY = nowY + moveY[i];

                if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;

                if(ans[nextX][nextY] > value + 1){
                    q.add(new Pair<>(nextX, nextY));
                    ans[nextX][nextY] = value + 1;
                }
            }
        }
    }

    public static void solving(){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char c = board[i].charAt(j);
                if(c == '1') checking(i,j);
            }
        }
    }

    public static void printing(){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) throws IOException{
        initializng();
        inputVariable();
        preProcessing();
        solving();
        printing();
    }
}
