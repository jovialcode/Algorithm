import java.util.*;

public class Main {
    public static int MAX_NUM = 101;
    static final int[] moveX = {1, 0, -1, 0}; //아래, 왼쪽, 위, 오른쪽
    static final int[] moveY = {0, -1, 0, 1};

    static int N, K, L;
    static int[][] board;
    static Queue<Order> queue;
    static class Order{
        int time;
        char cmd;

        public Order(int time, char cmd) {
            this.time = time;
            this.cmd = cmd;
        }
    }

    static class Pos{
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static{
        board = new int[MAX_NUM][MAX_NUM];
        queue = new LinkedList<>();
    }

    public static void input(){
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        K = scanner.nextInt();

        for (int i = 0; i <K; i++) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            board[x][y] = 1; // Apple;
        }

        L = scanner.nextInt();
        int prevTime = 0;
        for (int i = 0; i <L; i++) {
            int x = scanner.nextInt();
            String y = scanner.next();
            queue.add(new Order(x-prevTime, y.charAt(0)));
            prevTime = x;
        }
    }

        public static int sol(){
            int ans = 0;
            // 0 : 아래
            // 1 : 왼
            // 2 : 위
            // 3 : 오른쪽
            int curWay = 3;
            boolean crush = false;

            board[1][1] = 2;
            Deque<Pos> snake = new LinkedList();
            snake.addFirst(new Pos(1,1));

            while(!crush){
                int time;
                char cmd;
                Order order = queue.poll();
                if(Objects.isNull(order)){
                    time = MAX_NUM;
                    cmd = 'E';
                }else{
                    time = order.time;
                    cmd = order.cmd;
                }
                for(int i = 0 ; i < time; i++){
                    Pos head = snake.getFirst();
                    Pos tail = snake.getLast();
                    boolean apple = false;
                    ans += 1;
                    int nextX = head.x + moveX[curWay];
                    int nextY = head.y + moveY[curWay];

                    //벽 & 몸통 충돌 여부
                    if(nextX < 1 || nextX > N || nextY < 1 || nextY > N || board[nextX][nextY] == 2){
                        crush = true;
                        break;
                    }

                    if(board[nextX][nextY] == 1){
                        //사과 지우기
                        board[nextX][nextY] = 0;
                        apple = true;
                    }

                    if(!apple){
                        board[tail.x][tail.y] = 0;
                        snake.pollLast();
                    }

                    board[nextX][nextY] = 2;
                    snake.addFirst(new Pos(nextX, nextY));
                }

                curWay = getNextWay(curWay, cmd);
            }
        return ans;
    }

    public static int getNextWay(int cur, char cmd){
        int nextCur;
        switch (cmd){
            case 'D' : {
                nextCur = cur + 1;
                break;
            }
            case 'L' : {
                nextCur = cur -1;
                break;
            }
            default: return cur;
        }

        if(nextCur < 0){
            return 3;
        }else if(nextCur >3){
            return 0;
        }

        return nextCur;
    }

    public static void main(String[] args){
        input();
        System.out.println(sol());
    }
}
