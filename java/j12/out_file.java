/*
 * out_file.java
 * Copyright (C) 2016 claviering 
 *
 * Distributed under terms of the WTFPL license.
 */

import java.io.FileOutputStream;
import java.io.IOException;

public class out_file
{
	public static void main(String[] args) 
    {
		String s = "out out out";
        byte[] b = s.getBytes();
        try
        {
            FileOutputStream f = new FileOutputStream("out.text");
            f.write(b);
            f.flush();
            f.close();
        }
        catch (IOException e)
        {
            System.out.println("ERROR");
            e.printStackTrace();
        }
	}
}

