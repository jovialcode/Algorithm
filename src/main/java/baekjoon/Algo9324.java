package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Algo9324 {
    static int T;

    static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        T = Integer.parseInt(st.nextToken());
        for(int i = 0; i < T; i++){
            st = new StringTokenizer(br.readLine());
            print(sol(st.nextToken()));
        }
    }
    public static String sol(String str){
        String ans = "OK";
        int[] nums = new int[27];
        int len = str.length(), idx, next;
        Arrays.fill(nums,0);

        for(int i = 0; i < len; i++){
            idx = str.charAt(i) - 'A';

            nums[idx] += 1;
            if(nums[idx] % 3 == 0){
                next = i + 1;
                if(next >= len) return ans ="FAKE";
                if( str.charAt(i) != str.charAt(next)) return ans = "FAKE";

                i += 1;
            }
        }

        return ans;
    }

    public static void print(String val){
        System.out.println(val);
    }

    public static void main(String[] args) throws IOException{
        init();
    }
}
