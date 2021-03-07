package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Algo2206 {
    private static int N, M;
    private static int MAX_NUM = 1001;
    private static boolean[][] board;
    private static boolean[][][] visit;
    private static int[] moveX = {-1, 0, 1, 0};
    private static int[] moveY = {0, -1, 0, 1};

    public static class Info implements Comparable<Info>{
        private int cost, x, y, k;
        Info(int cost, int x, int y, int k) {
            this.cost = cost;
            this.x = x;
            this.y = y;
            this.k = k;
        }

        @Override
        public int compareTo(Info o) {
            return this.cost > o.cost ? 1 : -1;
        }
    }

    static {
        board = new boolean[MAX_NUM][MAX_NUM];
        visit = new boolean[MAX_NUM][MAX_NUM][2];
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String line = st.nextToken();
            for (int j = 0; j < M; j++) {
                board[i][j] = line.charAt(j) == '1';
            }
        }
    }

    public static int sol(int startX, int startY){
        int ans = -1;

        Queue<Info> queue = new PriorityQueue<>();
        queue.add(new Info(1, startX, startY, 1));

        while(!queue.isEmpty()){
            Info info = queue.poll();
            int x = info.x;
            int y = info.y;
            int cost = info.cost;
            int k = info.k;

            if(x == N-1 && y == M-1){
                ans = cost;
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];

                if(nextX < 0 || nextY < 0 || nextX >= N || nextY >= M) continue;
                if(visit[nextX][nextY][k]) continue;

                visit[nextX][nextY][k] = true;
                if(board[nextX][nextY] && k > 0){
                    queue.add(new Info(cost + 1, nextX, nextY, k - 1));
                }else if(!board[nextX][nextY]){
                    queue.add(new Info(cost + 1, nextX, nextY, k));
                }
            }
        }

        return ans;
    }

    public static void main(String[] args) throws IOException{
        input();
        System.out.println(sol(0,0));
    }
}
