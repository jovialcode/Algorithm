import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Algo2810 {
    static int N;
    static String str;

    public static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        str = new StringTokenizer(br.readLine()).nextToken();
    }

    public static int sol(){
        int ans = 0;
        boolean hasL = false;
        for(int i = 0; i < str.length(); i++){
            ans += 1;
            if(str.charAt(i) == 'L') { i += 1; hasL = true;}
        }
        if(hasL) ans+=1;
        return ans;
    }

    public static void main(String[] args) throws IOException{
        init();
        System.out.print(sol());
    }
}
