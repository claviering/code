/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package my_math;

/**
 *
 * @author sunn
 */
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
    
    public double GetArea()
    {
        return this.area;
    }
    
    public double GetPerimeter()
    {
        return this.perimeter;
    }
}

