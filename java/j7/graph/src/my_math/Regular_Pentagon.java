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

public class Regular_Pentagon extends Graph
{
   public double n; 

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
   
    public double GetArea()
    {
        return this.area;
    }
    
    public double GetPerimeter()
    {
        return this.perimeter;
    }
}

