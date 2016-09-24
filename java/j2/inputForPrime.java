/*************************************************************************
	> File Name: T2.java
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 02:32:15 PM CST
 ************************************************************************/
public class inputForPrime
{
    public static void main(String[] args)
    {
        int n = Integer.parseInt(args[0]);
        int m = Integer.parseInt(args[1]);
        isPrime(n,m);
    }
    public static void isPrime(int n, int m)
    {
        for (int i = n; i < m; i++)
        {
            int sq = (int)Math.sqrt(i);
            boolean flag = true;
            for (int j = 2; j < sq; j++)
            {
                if (i % j == 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                System.out.print(i+" ");
        }
        System.out.println();
    }
}
