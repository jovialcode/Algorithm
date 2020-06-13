import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;

public class Algo2140 {
    private static int N;
    private static int[][] board;
    private static int[] moveX = new int[]{-1,-1,-1,0,0,1,1,1};
    private static int[] moveY = new int[]{-1,0,1,-1,1,-1,0,1};

    public static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new int[N+1][N+1];
        for(int i = 0; i<N; i++){
            String str = br.readLine();
            for(int j = 0; j< str.length(); j++){
                char c = str.charAt(j);
                board[i][j]  = (c != '#' ? Character.getNumericValue(c) : 999);
            }
        }
    }

    public static void sol(){
        int ans = 0;
        for(int i = 1; i < N-1; i++){
            for(int j = 1; j< N-1; j++){
                if(check(i,j)) ans += 1;
            }
        }
        print(ans);
    }

    public static boolean check(int x, int y) {
        boolean okay = true;
        for(int i = 0; i<8; i++){
            int nextX = x + moveX[i];
            int nextY = y + moveY[i];

            if(board[nextX][nextY] <= 0) {
                okay = false;
                break;
            }
        }

        if(okay){
            for(int i = 0; i<8; i++){
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];

                board[nextX][nextY] -= 1;
            }
        }
        return okay;
    }

    public static void print(Vector<String> v) {
        for (String s : v) {
            System.out.println(String.format("%s",s));
        }
    }

    public static void print(int n){
        System.out.print(n);
    }

    public static void main(String ... args) throws IOException{
        input();
        sol();
    }
}
