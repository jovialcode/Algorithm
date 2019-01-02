import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		scan.close();

		if (N > 54) {
			for (int i = N - 54; i < N; i++) {
				int tempValue = i;
				int tempSum = tempValue;
				while (tempValue > 0) {
					tempSum += tempValue % 10;
					tempValue /= 10;
				}
				if (tempSum == N) {
					System.out.println(i);
					return;
				}
			}
		} else {
			for (int i = 1; i < N; i++) {
				int tempValue = i;
				int tempSum = tempValue;
				while (tempValue > 0) {
					tempSum += tempValue % 10;
					tempValue /= 10;
				}
				if (tempSum == N) {
					System.out.println(i);
					return;
				}
			}
		}
		System.out.println("0");
		
	}
}
