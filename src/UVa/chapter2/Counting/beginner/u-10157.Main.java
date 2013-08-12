import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static final int MAXN = 160;
    public static void main(String[] args) {
	BigInteger[][] dp = new BigInteger[MAXN][MAXN];
	int n = MAXN - 1;

	for(int i = 0; i <= n; i++)
	    for(int j = 0; j <= n; j++)
		dp[i][j] = new BigInteger("0");

	for(int i = 0; i <= n; i++)
	    dp[0][i] = new BigInteger("1");

	for(int i = 1; i <= n; i++)
	    for(int j = 1; j <= n; j++)
		for(int k = 0; k <= i - 1; k++)
		    dp[i][j] = dp[i][j].add(dp[k][j-1].multiply(dp[i - k - 1][j]));

	Scanner cin = new Scanner(System.in);
	while(cin.hasNextInt()){
	    n = cin.nextInt();
	    int d = cin.nextInt();
	    if(n % 2 == 0)
		System.out.println(dp[n/2][d].subtract(dp[n/2][d - 1]));
	    else
		System.out.println(0);
	}
    }

}

