/********************************************************************
	> File Name: use-vector.java
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 05:24:56 AM EDT
 *******************************************************************/
import java.util.*;

class use_vertor
{
    public static void main(String[] args)
    {
        Vector<Integer> v_i = new Vector<Integer>();
        for (int i = 0; i < 10; i++)
            v_i.addElement(new Integer(i));
        Enumeration vEnum = v_i.elements();
        while (vEnum.hasMoreElements())
            System.out.println(vEnum.nextElement());
    }
}
