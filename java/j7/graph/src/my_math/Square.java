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

public class Square extends Graph
{
    public double n;

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
    
    public double GetArea()
    {
        return this.area;
    }
    
    public double GetPerimeter()
    {
        return this.perimeter;
    }
}

