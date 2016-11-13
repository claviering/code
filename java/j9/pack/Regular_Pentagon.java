/**********************************************************************
	> File Name: Regular_Pentagon.java
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 12:37:39 PM CST
 *********************************************************************/

    /*
     *TODO:draw a Regular_Pentagon
     */
package my_math;

import java.awt.*;
import my_math.Graph;

public class Regular_Pentagon extends Graph
{
    public double n; 

    public Regular_Pentagon(int x, int y, int width, int height, Color color )
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
    /*
     *TODO:draw a Regular_Pentagon
     */
    }

    public void calc_area()
    {
        this.area = (5 * n * n) / (4 * Math.tan(36));
    }

    public void calc_perimeter()
    {
        this.perimeter = 5 * n;
    }

    public void display_area()
    {
        System.out.println("the Regular Pentagon area: " + this.area);
    }

    public void display_perimeter()
    {
        System.out.println("the Regular Pentagon perimeter: " + this.perimeter);
    }

    public String toString()
    {
        return Double.toString(this.area); 
    }
}
