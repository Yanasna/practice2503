package practice;

import java.util.Scanner;

public class SuccessOrFail {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("점수를 입력하세요 : ");
		int score = scanner.nextInt();
		if(score >= 80) 
		{
			System.out.println("축하합니다. 합격입니다.");
		}
		else
		{
			System.out.println("자격미달입니다. ");
		}
		scanner.close();
		
	}

}
