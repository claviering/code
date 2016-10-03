import java.util.*;
class p118_6
{
    static int num;
    public static void main(String[] args)        
    {
        try
        {
            num = Integer.parseInt(args[0]);
        }
        catch(Exception e)
        {
            System.out.println("ERROR");
            System.exit(0);
        }
        System.out.println("the Binary is :" + Integer.toBinaryString(num));
        System.out.println("the Octal is :" + Integer.toOctalString(num));
        System.out.println("the Hex is :" + Integer.toHexString(num));
        //decimal_to_binary(num);
    }
    public static void decimal_to_binary(int num)
    {
        Stack<Integer> st = new Stack<Integer>();
        try
        {
            while (num > 0 || num < 0)
            {
                st.push(num & 1);
                if (num > 0)
                    num >>= 1;
                else 
                    num >>>= 1;
            }

        }
        catch(Exception e)
        {
            System.out.println("ERROR");

        }

        while (!st.empty())
        {
            System.out.print(st.pop() + " ");
        }
        System.out.println();

    }
}
