package baekjoon;

import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Algo10539 {
    static int bSize;
    static ArrayList<Integer> b = new ArrayList<>();

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        bSize = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i <= bSize; i++){
            b.add(Integer.parseInt(st.nextToken()));
        }
    }

    public static void sol(){
        int sum = 0, val;
        for(int i = 0; i < bSize; i++){
            val = b.get(i) * (i + 1) - sum;
            System.out.print(val + " ");
            sum += val;
        }
    }

    public static void fileIn() throws IOException {
        //파일 객체 생성
        String filePath = "D:\\download\\contest1_testdata\\prosjek\\prosjek.in.9";
        File file = null; // 파일 스트림
        try {
            file = new File(filePath);
            if (file.exists()) {
                BufferedReader inFile = new BufferedReader(new FileReader(file));
                StringTokenizer st = new StringTokenizer(inFile.readLine());

                bSize = Integer.parseInt(st.nextToken());
                st = new StringTokenizer(inFile.readLine());
                for(int i = 0; i < bSize; i++){
                    b.add(Integer.parseInt(st.nextToken()));
                }
            }
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static void main(String[] args) throws IOException{
        init();
        sol();
    }
}
