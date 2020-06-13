import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Algo3184 {

    public static int N;
    public static int M;
    public static int solS;
    public static int solW;
    public static char[][] board;
    public static int[] moveX = new int[] {0, 0, -1, 1};
    public static int[] moveY = new int[] {-1, 1, 0, 0};
    public static boolean[][] visit;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new char[N + 1][M + 1];

        for(int i = 0; i < N; i++){
            String str = br.readLine();
            for(int j = 0; j< str.length(); j++){
                board[i][j] = str.charAt(j);
            }
        }

        visit = new boolean[N][M];
        solS = solW = 0;
    }

    public static void output(){
        System.out.println(solS + " " + solW);
    }

    public static void bfs(int x, int y){
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int sheep = 0, wolf = 0;

        q.offer(new Pair(x, y));

        while(!q.isEmpty()){
            char c;
            Pair<Integer,Integer> p = q.poll();
            Integer curX = p.getKey();
            Integer curY = p.getValue();

            c = board[curX][curY];
            if(c == 'o') sheep += 1;
            else if(c == 'v') wolf += 1;

            for(int i = 0; i < 4; i++){
                int nextX = curX + moveX[i], nextY = curY + moveY[i];

                if(!howThere(nextX, nextY)) continue;
                visit[nextX][nextY] = true;

                q.offer(new Pair(nextX,nextY));
            }
        }


        if(sheep > wolf) solS += sheep;
        else solW += wolf;
    }

    public static boolean howThere(int x, int y){
        if(x < 0 || y < 0 || x == N || y == M) return false;
        if(board[x][y] == '#') return false;
        if(visit[x][y]) return false;
        return  true;
    }

    public static void main(String[] args) throws IOException{
        init();

        for(int i = 0; i < N; i++) {
            for(int j = 0; j< M; j++){
                if(!visit[i][j] && board[i][j] != '#') {
                    visit[i][j] = true;
                    bfs(i, j);
                }
            }
        }

        output();
    }
}
