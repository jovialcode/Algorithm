package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo10409 {
    static int N, T;

    public static int init() throws IOException {
        int ans, sum;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        ans = sum = 0;

        for(int i = 0; i < N; i++){
            sum += Integer.parseInt(st.nextToken());
            if(sum <= T ) ans += 1;
        }
        return ans;
    }


    public static void main(String[] args) throws IOException{
        System.out.print(init());
    }
}
