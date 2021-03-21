package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Algo17135 {
    static final int MAX_NUM = 16;
    static final int[] moveX = {0, 0, 1, 0};
    static final int[] moveY = {0, -1, 0, 1};
    static int N, M, D;
    static int[][] board;
    static int[][] kill;

    static{
        board = new int[MAX_NUM][MAX_NUM];
    }

    public static class MoveInfo implements Comparable<MoveInfo>{
        int dist;
        int x;
        int y;
        MoveInfo(int dist, int x, int y){
            this.dist = dist;
            this.x = x;
            this.y = y;
        }
        @Override
        public int compareTo(MoveInfo o) {
            if(this.dist > o.dist) return 1;
            else if(this.dist == o.dist){
                return this.y > o.y ? 1 : -1;
            }else{
                return -1;
            }
        }
    }

    public static void input(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            D = Integer.parseInt(st.nextToken());

            for (int i = N-1; i >= 0; i--) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static int sol(int pos1, int pos2, int pos3){
        // 한줄 씩올라감
        for (int i = 0; i < N; i++) {
            findEnemyAndKill(i, pos1);
            findEnemyAndKill(i, pos2);
            findEnemyAndKill(i, pos3);


            for (int j = i; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    if(kill[j][k] == 1) kill[j][k] = -1;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N ; i++) {
            for (int j = 0; j < M; j++) {
                ans += kill[i][j] != 0 ? 1:0;
            }
        }

        return ans;
    }

    public static void cleanUp(){
        kill = new int[MAX_NUM][MAX_NUM];
    }

    public static int dis(int fromX, int fromY, int toX, int toY){
        return Math.abs(toX- fromX) + Math.abs(toY- fromY);
    }

    public static void findEnemyAndKill(int fromX, int fromY){
        Queue<MoveInfo> queue = new PriorityQueue<>();
        queue.add(new MoveInfo(0, fromX, fromY));
        boolean[][] visit = new boolean[MAX_NUM][MAX_NUM];

        while(!queue.isEmpty()){
            MoveInfo m = queue.poll();
            for(int i = 0; i < 4; i++){
                int nextX = m.x + moveX[i];
                int nextY = m.y + moveY[i];

                if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
                if(visit[nextX][nextY]) continue;

                int nextDist = dis(fromX, fromY, nextX, nextY);
                if(nextDist > D-1) continue;

                visit[nextX][nextY] = true;
                if(board[nextX][nextY] == 1 && kill[nextX][nextY] != -1){
                    kill[nextX][nextY] = 1;
                    return ;
                }

                queue.add(new MoveInfo(nextDist, nextX, nextY));
            }
        }
    }

    public static void main(String[] args){
        input();
        int maxAns = 0;
        for (int i = 0; i < M; i++) {
            for (int j = i + 1; j < M; j++) {
                for (int k = j + 1; k < M; k++) {
                    cleanUp();
                    maxAns = Math.max(maxAns, sol(i, j, k));
                }
            }
        }
        System.out.println(maxAns);
    }
}
