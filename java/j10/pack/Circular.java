/*************************************************************************
	> File Name: Circular.java
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 12:36:57 PM CST
 ************************************************************************/
package my_math;

import java.awt.*;
import my_math.Graph;

public class Circular extends Graph
{
    public double r;
    public double PI = 3.14159;

    public Circular(int x, int y, int width, int height, Color color )
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
        g.drawOval(x, y, width, height); // drwa a oval 
    }

    public void calc_area()
    {
        this.area = PI * r * r;
    }

    public void calc_perimeter()
    {
        this.perimeter = 2 * PI * r;
    }

    public void display_area()
    {
        System.out.println("the Circular area: " + this.area);
    }

    public void display_perimeter()
    {

        System.out.println("the Circular perimeter: " + this.perimeter);
    }

    public String toString()
    {
        return Double.toString(this.area); 
    }
}

