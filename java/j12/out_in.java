/*
 * out_in.java
 * Copyright (C) 2016 claviering 
 *
 * Distributed under terms of the WTFPL license.
 */
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
public class out_in
{
    public static void main(String args[])
    {
        try
        {
            FileOutputStream fout = new FileOutputStream("hout.txt");
            DataOutputStream dfout =new DataOutputStream(fout);
            char i;
            for (i = 'a'; i <= 'd'; i++)
                dfout.writeChar(i);
            dfout.close();

            FileInputStream fin = new FileInputStream("hout.txt");
            DataInputStream dfin = new DataInputStream(fin);
            int x;
            for (x = 0; x < 4; x++)
                System.out.print(dfin.readChar() + ", ");
            dfin.close();
        }
        catch (Exception e)
        {
            System.err.println("发生异常:" + e);
            e.printStackTrace();
        } 
    } 
} 

