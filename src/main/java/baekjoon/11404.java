import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int MAX_NUM = 101;
    static final int MAX_COST = 10000001;
    static int N, M;
    static int[][] cost;

    static{
        cost = new int[MAX_NUM][MAX_NUM];

        for (int i = 0; i < MAX_NUM; i++) {
            for (int j = 0; j < MAX_NUM; j++) {
                cost[i][j] = MAX_COST;
            }
        }
    }

    public static void input(){
        try{
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());

            for (int i = 0; i <M ; i++) {
                st = new StringTokenizer(br.readLine());

                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                cost[from-1][to-1] = Math.min(cost[from-1][to-1], c);
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void sol(){
        for (int k = 0; k <= N; k++) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j <= N; j++) {
                    if ( i == j || i == k || k == j) continue;
                    if (cost[i][k] == MAX_COST || cost[k][j] == MAX_COST ) continue;
                    if (cost[i][j] > cost[i][k] + cost[k][j]) cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    public static void print(){
        for (int i = 0; i <N ; i++) {
            for(int j = 0; j <N; j++){
                System.out.print(cost[i][j] == MAX_COST ? "0 ": cost[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args){
        input();
        sol();
        print();
    }
}
