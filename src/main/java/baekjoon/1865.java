import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static final int MAX_NODE = 501;
    public static final int MAX_EDGE = 2501;
    public static final long MAX_COST = 10001;

    public static int T;
    public static int N, M, W;
    public static long[] node;
    public static List<Edge> edgeList;
    public static BufferedReader br;

    public static class Edge{
        int start;
        int end;
        int cost;
        Edge(int start, int end, int cost){
            this.start = start;
            this.end = end;
            this.cost = cost;
        }
    }

    public static void cleanup(){
        edgeList = new ArrayList<>();
        node = new long[MAX_NODE];
        for (int i = 0; i <N ; i++) {
            node[i] = MAX_COST;
        }
    }

    public static void input() throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        for (int i = 0; i <M + W; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            if(i >= M){
                edgeList.add(new Edge(start -1, end -1, -cost));
                continue;
            }
            edgeList.add(new Edge(start -1, end -1, cost));
            edgeList.add(new Edge(end -1, start -1, cost));

        }
    }

    public static String sol(){
        boolean canDo = false;
        node[0] = 0;

        //edge relaxation
        //노드 수 만큼 돌려서 마지막을 체크한다.
        for (int i = 0; i <= N; i++) {
            for(Edge edge : edgeList){
                int start = edge.start;
                int end = edge.end;
                int cost = edge.cost;
                
                if(node[end] > node[start] + cost){
                    node[end] = node[start] + cost;
                    
                    if(i == N){
                        canDo = true;
                    }
                }
            }
        }

        return canDo ? "YES" : "NO";
    }

    public static void main(String[] args) throws IOException{
        try{
            br = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(br.readLine());
            T = Integer.parseInt(st.nextToken());

            while(T-- > 0){
                cleanup();
                input();
                System.out.println(sol());
            }
        }catch (IOException e){
            e.printStackTrace();
        }finally {
            br.close();
        }
    }
}
