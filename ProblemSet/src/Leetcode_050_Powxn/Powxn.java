package Leetcode_050_Powxn;

/*
	
*/
public class Powxn {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double x = 2.00000;
		int n = 12;
		Powxn pxn = new Powxn();
		System.out.println(pxn.myPow(x, n));
	
	}

	// 50.Pow(x,n)
	public double myPow(double x, int n) {
		
		if (n == 0 || x == 1) {
			return 1;
		}
	
		if (n == Integer.MIN_VALUE && x == -1) {
			return 1;
		}
		if (n == Integer.MIN_VALUE) {
			return 0;
		}
		double num = 1.0;
		int m = Math.abs(n);
		while (m > 0) {
			
			if(m%2==1) {
				num*=x;				
			}
			x *= x;
			m >>= 1;
		}
		if (n < 0) {
			num = 1.0 / num;
		}
		return num;
	}

}