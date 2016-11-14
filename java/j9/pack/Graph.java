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
import java.awt.*;

public abstract class Graph
{
    public double area;
    public double perimeter;
    public int x;
    public int y;
    public int width;
    public int height;
    public Color color = Color.RED;


    public abstract void calc_area();
    public abstract void display_area();
    public abstract void calc_perimeter();
    public abstract void display_perimeter();
    public abstract String toString();
    public abstract void paint(Graphics g);
}




