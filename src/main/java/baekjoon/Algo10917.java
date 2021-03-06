import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

// 최단 거리를 찾는 문제
public class Main {
    private static int MAX_NUM = 100001;
    private static int N, M;
    private static List<List<Integer>> board;
    private static boolean[] visit;
    private static class Pair implements Comparable<Pair>{
        private int count;
        private int node;

        Pair(int count, int node){
            this.count = count;
            this.node = node;
        }

        @Override
        public int compareTo(Pair o) {
            return this.count > o.count ? 1 : -1;
        }
    }

    static {
        visit = new boolean[MAX_NUM];
        board = new ArrayList<>(MAX_NUM);
        for (int i = 0; i < MAX_NUM ; i++) {
            board.add(new ArrayList<>());
        }
    }

    public static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());

            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            board.get(x).add(y);
        }
    }

    //bfs로 최단거리 구하기
    public static int sol(int start){
        int ans = -1;
        Queue<Pair> queue = new PriorityQueue<>();
        queue.add(new Pair(0, start));

        while (!queue.isEmpty()){
            Pair fromNode = queue.poll();
            int count = fromNode.count;
            int node = fromNode.node;

            if(node == N){
                ans = count;
                break;
            }

            List<Integer> tos = board.get(node);

            for (int to : tos) {
                if(visit[to]) continue;
                queue.add(new Pair(count+1, to));
                visit[to] = true;
            }
        }
        return ans;
    }

    public static void main(String[] args) throws IOException{
        input();
        System.out.println(sol(1));
    }
}
