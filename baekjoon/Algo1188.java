import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo1188 {
    static int N, M;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
    }

    public static void print(int val){
        System.out.println(val);
    }

    public static int sol(){
        int ans = 0;
        if(N > M) N -= M;
        ans = M - gcd(N, M);

        return ans;
    }

    public static int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException{
        init();
        if(N == M || N % M == 0) print(0);
        else print(sol());
    }
}
