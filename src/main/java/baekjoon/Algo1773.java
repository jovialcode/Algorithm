package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Algo1773 {
    static int N, C;
    static int[] stu = new int[101];
    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        for(int i = 0; i< N; i++){
            st = new StringTokenizer(br.readLine());
            stu[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(stu, 0, N-1);
    }

    public static int sol(){
        int ans = 0;
        for(int i = 1; i <= C; i++){
            for(int j = 0; j < N; j++){
                if(i % stu[j] == 0) { ans += 1; break; }
            }
        }

        return ans;
    }
    public static void main(String[] args) throws IOException{
        init();
        System.out.println(sol());
    }
}
