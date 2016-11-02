//usage java main -c [radius] -r [side length of Regular Pentagon] -s [side length of Square] -t [edge a] [edge b] [edge c]  
import my_math.Graph;
import my_math.Circular;
import my_math.Regular_Pentagon;
import my_math.Square;
import my_math.Triangle;

public class main
{
    public static void main(String[] args)
    {
        calc in = new calc();
        in.input_date(args);
        in.display_total();
    }
}

class calc
{
    public double total_area;
    public double total_perimeter;

    Circular cir = new Circular();
    Regular_Pentagon reg = new Regular_Pentagon();
    Square sq = new Square();
    Triangle tri = new Triangle();

    public void input_date(String[] args)
    {
        for (int i = 0; i < args.length; i++)    
        {
            if (args[i].equals("-c"))
            {
                cir.r = Double.parseDouble(args[++i]);        

                cir.calc_area();
                cir.calc_perimeter();
                cir.display_area();
                cir.display_perimeter();
            }
            else if (args[i].equals("-r"))
            {
                reg.n = Double.parseDouble(args[++i]);

                reg.calc_area();
                reg.calc_perimeter();
                reg.display_area();
                reg.display_perimeter();
            }
            else if (args[i].equals("-s"))
            {
                sq.n = Double.parseDouble(args[++i]);

                sq.calc_area();
                sq.calc_perimeter();
                sq.display_area();
                sq.display_perimeter();
            }
            else if (args[i].equals("-t"))
            {
                tri.a = Double.parseDouble(args[++i]);
                tri.b = Double.parseDouble(args[++i]);
                tri.c = Double.parseDouble(args[++i]);

                tri.calc_area();
                tri.calc_perimeter();
                tri.display_area();
                tri.display_perimeter();
            }
        }

        this.total_area = cir.area + reg.area + sq.area + tri.area;
        this.total_perimeter = cir.perimeter + reg.perimeter + sq.perimeter + tri.perimeter;
    }

    public void display_total()
    {
        System.out.println("the total area: " + this.total_area);
        System.out.println("the total perimeter: " + this.total_perimeter);
    }
}

