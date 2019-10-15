import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
    private static String str;
    private final static String stopSignoal = "(^0^)";
    private final static Pattern leftPattern = Pattern.compile("@+(=)");
    private final static Pattern rightPattern = Pattern.compile("=@");

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        str = br.readLine();
    }

    public static void sol(){
        int leftSol = 0;
        int rightSol = 0;
        HashMap<String, Integer> result = new HashMap<>();
        Matcher leftMatcher = leftPattern.matcher(str.substring(0,str.indexOf(stopSignoal)));
        Matcher rightMatcher = rightPattern.matcher(str.substring(str.indexOf(stopSignoal), str.length()));

        while (leftMatcher.find())
            leftSol++;

        while (rightMatcher.find())
            rightSol++;

        result.put("left",leftSol);
        result.put("right",rightSol);

        print(result);
    }

    public static void print(Map<String, Integer> result){
        System.out.print(String.format("%d %d",result.get("left"), result.get("right")));
    }

    public static void main(String[] args) throws IOException{
        input();
        sol();
    }
}
