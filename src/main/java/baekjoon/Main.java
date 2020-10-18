package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

public class Main {
    public static int N;
    public static List<Integer> nums;
    public static int[] sol;

    public static void main(String[] args){
        input();
        sol();
    }

    public static void input(){
        try(InputStreamReader is = new InputStreamReader(System.in);
            BufferedReader bufferedReader = new BufferedReader(is);
        ){
            StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
            N = Integer.parseInt(st.nextToken());
            nums = new ArrayList<>(N);
            sol = new int[N];

            String str = bufferedReader.readLine();
            nums = Arrays.stream(str.split(" "))
                    .map(num -> Integer.parseInt(num))
                    .collect(Collectors.toList());
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public static void sol(){
        for (int i = 0; i < N; i++) {
            int myPos = findPos(i + 1, nums.get(i));
            sol[myPos] = i + 1;
        }

        print();
    }

    public static int findPos(final int height, final int left){
        int pos = 0;
        for (int i = 0; i <N; i++) {
            int num = sol[i];
            if(pos == left && num == 0) {
                pos = i;
                break;
            }
            if (num == 0 || num > height) {
                pos += 1;
            }
        }
        return pos;
    }



    public static void print(){
        for (int i = 0; i < N; i++) {
            System.out.print(sol[i] + " ");
        }
    }
}
