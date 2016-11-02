/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sunn
 */
///<summer>
///计算图形的面积和周长
///<summer>

package my_math;

public abstract class Graph
{
    public double area;
    public double perimeter;

    public abstract void calc_area();
    public abstract void display_area();
    public abstract void calc_perimeter();
    public abstract void display_perimeter();
    public abstract double GetArea();
    public abstract double GetPerimeter();
    public abstract String toString();
}
