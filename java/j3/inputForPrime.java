/*************************************************************************
	> File Name: T2.java
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 02:32:15 PM CST
 ************************************************************************/
import javax.swing.JOptionPane;
import javax.swing.JTextField;

public class inputForPrime
{
    public static void main(String[] args)
    {
        long startTime = System.nanoTime();

        if (checkInput(args))
        {
            int n = Integer.parseInt(args[0]);
            int m = Integer.parseInt(args[1]);
            isPrime(n,m);
        }
        else 
        {
            usingDialog();
        }
        

        long endTime = System.nanoTime();
        displayRuningTime(startTime, endTime);

    }

    public static boolean checkInput(String[] args)
    {
        int argsLen = args.length;
        if (argsLen == 0)
        {
            return false;
        }
        else if (argsLen == 2)
        {
            try
            {
                int n = Integer.parseInt(args[0]);
                int m = Integer.parseInt(args[1]);
                return true;
            }
            catch(Exception e)
            {
                System.out.println("Input Error");
                System.exit(0);
            }
        }
        else 
        {
            System.out.println("Input Error");
            System.exit(0);
        }
        return false;

    }
    public static void usingDialog()
    {
        String firstInput = JOptionPane.showInputDialog("calc prime", "input the first Integer numbers");
        String secondInput = JOptionPane.showInputDialog("calc prime", "input the second Integer numbers");
        try
        {
            int n = Integer.parseInt(firstInput);
            int m = Integer.parseInt(secondInput);
            isPrime(n, m);
        }
        catch(Exception e)
        {
            System.out.println("Input Error");
        }
    }

    public static void isPrime(int n, int m)
    {
        if (n > m)
        {
            n = n ^ m;
            m = n ^ m;
            n = n ^ m;
        }
        String primeStr = new String();
        for (int i = n; i <= m; i++)
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
            {
                primeStr = primeStr + i + ",";
                System.out.print(i+" ");
            }
        }
        System.out.println();
        System.out.println("----");
        System.out.println(primeStr);
    }

    public static void displayRuningTime(long startTime, long endTime)
    {
        System.out.println();
        System.out.println("runing time");
        System.out.println(endTime - startTime + " ns");
        double ms = (double)(endTime - startTime) / 10e9;
        System.out.println(ms + " ms");
    }
}

