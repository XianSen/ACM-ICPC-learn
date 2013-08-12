import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static final int MAXN = 72;
    public static BigInteger[] pow2 = new BigInteger[MAXN];
    public static BigInteger[] f = null;

    public static int[] convert_to_binary(BigInteger n){
	int[] a = new int[MAXN];
	a[0] = 0;
	if(n.compareTo(BigInteger.ZERO) == 0){
	    a[0] = 1;
	    a[1] = 0;
	    return a;
	}

	BigInteger two = new BigInteger("2");
	while(n.compareTo(BigInteger.ZERO) != 0){
	    a[++ a[0]] = n.mod(two).intValue();
	    n = n.divide(two);
	}
	return a;
    }

    public static BigInteger calc(BigInteger n){
	int[] a = convert_to_binary(n);

	BigInteger ans = new BigInteger("0");
	BigInteger left = BigInteger.ZERO;
	BigInteger right = n;

	for(int i = a[0]; i > 0; i--){
	    if(a[i] == 1)
		left = left.add(pow2[i - 1]);

	    if(i != a[0] && a[i] == 1 && a[i + 1] == 1){
		BigInteger now = right.subtract(pow2[i - 1]);
		ans = ans.add(now.add( new BigInteger("1")));
	    }

	    if(a[i] == 1){
		ans = ans.add(f[i - 1]);
		//				System.out.println(f[i-1]);
	    }

	    if(a[i] == 1)
		right = right.subtract(pow2[i - 1]);
	}

	return ans;
    }

    public static BigInteger[] init(){
	BigInteger[][] dp = new BigInteger[MAXN][2];
	BigInteger[] f = new BigInteger[MAXN];

	for(int i = 0; i < MAXN; i++)
	    f[i] = new BigInteger("0");

	for(int i = 0; i < MAXN; i++)
	    for(int j = 0; j < 2; j++)
		dp[i][j] = new BigInteger("0");

	int n = 70;
	BigInteger two = new BigInteger("2");

	pow2[0] = new BigInteger("1");
	for(int i = 1; i <= n; i++)
	    pow2[i] = pow2[i - 1].multiply(two);


	for(int i = 2; i <= n; i++){
	    dp[i][1] = dp[i-1][0].add(dp[i-1][1]);
	    dp[i][1] = dp[i][1].add(pow2[i - 2]);

	    dp[i][0] = dp[i - 1][0].add(dp[i - 1][1]);

	}

	for(int i = 0; i <= n; i++)
	    f[i] = dp[i][0].add(dp[i][1]);

	return f;
    }

    public static void main(String[] args) {
	int kcase = 0;
	f = init();

	Scanner cin = new Scanner(System.in);
	while(cin.hasNext()){
	    BigInteger n = new BigInteger(cin.nextLine());
	    System.out.println(n);
	    if(n.compareTo(BigInteger.ZERO) < 0)
		break;
	    kcase++;
	    BigInteger ans = calc(n);
	    System.out.println("Case " + kcase + ": " + ans);
	}
	}

}

