/*************************************************************************
	> File Name: Triangle.java
	> Author: 
	> Mail: 
	> Created Time: Sat 15 Oct 2016 12:34:58 PM CST
 ************************************************************************/
package my_math;

import my_math.Graph;


public class Triangle extends Graph
{
    public double a;
    public double b;
    public double c;
    public void calc_area()
    {
        double p = (a + b + c) / 2;
        this.area = Math.sqrt(p * (p - a) * (p - b) * (p - c));
    }
    public void calc_perimeter()
    {
        this.perimeter = a + b + c;
    }
    public void display_area()
    {
        System.out.println("the Triangle area: " + this.area);
    }
    public void display_perimeter()
    {

        System.out.println("the Triangle perimeter: " + this.perimeter);
    }
    public String toString()
    {
        return Double.toString(this.area); 
    }
}
