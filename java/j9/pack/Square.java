/*************************************************************************
	> File Name: Square.java
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 12:35:47 PM CST
 ************************************************************************/
package my_math;

import java.awt.*;
import my_math.Graph;

public class Square extends Graph
{
    public double n;
    public Square(int x, int y, int width, int height, Color color )
    {
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.color = color;
    }
    
    // Paint itself given the Graphics context
    public void paint(Graphics g) 
    {
        g.setColor(color);
        g.drawRect(x, y, width, height); // drwa a Rect
    }

    public void calc_area()
    {
        this.area = n * n;
    }
    public void calc_perimeter()
    {
        this.perimeter = 4 * n;
    }
    public void display_area()
    {
        System.out.println("the Square area: " + this.area);
    }
    public void display_perimeter()
    {

        System.out.println("the Square perimeter: " + this.perimeter);
    }
    public String toString()
    {
        return Double.toString(this.area); 
    }
}
