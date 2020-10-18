package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo2909 {
    static int C, K;
    static final int[] POWERS_OF_10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    static int powerOfTen(int pow) {
        return POWERS_OF_10[pow];
    }

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        C = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
    }

    public static int sol(){
        int ans = C, num, pot = powerOfTen(K);
        num = C % pot;
        if(num >= (pot/2)) ans += pot;
        ans -= num;
        return ans;
    }

    public static int intLength(){
        int len = 0, temp = C;
        while(temp > 0){
            len +=1;
            temp/= 10;
        }
        return len;
    }

    public static void main(String[] args) throws IOException{
        init();
        System.out.println(sol());
    }
}
