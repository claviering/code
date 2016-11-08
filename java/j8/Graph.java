/**********************************************************************
	> File Name: my_math.java
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 08:39:16 AM CST
 *********************************************************************/
///<summer>
///计算图形的面积和周长
///<summer>

package my_math;

public abstract class Graph
{
    public double area;
    public double perimeter;
    public double x;
    public double y;

    public int r,g,b;

    public abstract void calc_area();
    public abstract void display_area();
    public abstract void calc_perimeter();
    public abstract void display_perimeter();
    public abstract String toString();
}




