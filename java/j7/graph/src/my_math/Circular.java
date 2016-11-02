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

public class Circular extends Graph
{
    public double r;
    public double PI = 3.14159;

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
    
    public double GetArea()
    {
        return this.area;
    }
    
    public double GetPerimeter()
    {
        return this.perimeter;
    }
}


