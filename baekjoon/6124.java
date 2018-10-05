import java.util.Scanner;

public class GoodGrass6124 {

	public static int N,M,maxSum,solR,solC;
	public static int[][] board;
	public static int[] moveX;
	public static int[] moveY;
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		board = new int[105][105];
		maxSum = 0;
		solR = solC = 1;
		moveX = new int[] {0,0,0,1,1,1,2,2,2};
		moveY = new int[] {0,1,2,0,1,2,0,1,2};
		
		N = scan.nextInt(); M = scan.nextInt();
		
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				board[i][j] = scan.nextInt();
			}
		}
		//입력정리
		for(int i = 1; i<=N-2; i++){
			for(int j = 1; j<=M-2; j++){
				int temp = 0 ;
				int x = i, y = j;
				
				for(int k = 0; k<9; k++){
					int mx = x+moveX[k];
					int my = y+moveY[k];
					temp += board[mx][my];
				}
				if(temp> maxSum){
					maxSum = temp;
					solR = i;
					solC = j;
				}
				
			}
		}
		System.out.println(maxSum);
		System.out.print(solR +" "+ solC);
		
	}
}
