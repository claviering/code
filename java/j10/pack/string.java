/*
 * string.java
 * Copyright (C) 2016 claviering 
 *
 * Distributed under terms of the WTFPL license.
 */

package my_math;

import java.awt.*;
import my_math.Graph;

public class string extends Graph
{
    public String s;
    public string(String s, int x, int y)
    {
        this.s = s;
        this.x = x;
        this.y = y;
    }
    
    // Paint itself given the Graphics context
    public void paint(Graphics g) 
    {
        g.setColor(color);
        g.drawString(s, x, y); // drwa a oval 
    }

    public void calc_area()
    {
    }

    public void calc_perimeter()
    {
    }

    public void display_area()
    {
    }

    public void display_perimeter()
    {

    }

    public String toString()
    {
        return "";
    }
}
