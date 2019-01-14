import java.util.Scanner;

public class Main {
		public static void main(String[] args){
			
			Scanner scan = new Scanner(System.in);
			long S = scan.nextLong();
			long cnt = (long)Math.sqrt(2*S);
			while(cnt *cnt  +cnt > 2*S){
					cnt--;
			}
			System.out.println(cnt);
		}
	
}
