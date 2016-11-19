/********************************************************************
	> File Name: my_frame.java
	> Author: lin 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 05:40:40 PM CST
 *******************************************************************/

/* 结构说明
 * class my_frame extends JFrame
 * |____ GetScreenSize() 获取屏幕大小函数
 * |____ Class DrawCanvas extends JPanel 画板类，把画好的图形add到Panel,再add到JFrame
 *         |____ paintComponent(Graphics g) 画图函数，g.draw
 * |____ ShowText() 点击菜单触发函数
 * |____ my_frame() 构造函数，显示图形界面
 */

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;
import javax.swing.UIManager.LookAndFeelInfo;

import my_math.*;


public class my_frame extends JFrame
{

    //get screen size
    public int max_size_width;
    public int max_size_hight;
    void GetScreenSize()
    {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        double width = screenSize.getWidth();
        double height = screenSize.getHeight();	
        max_size_width = (int)width;
        max_size_hight = (int)height;
    }

    // object to paint
    Circular cir = new Circular(0,0,0,0,Color.RED);
    Vector<Circular> v_cir = new Vector<Circular>();
    public void AddGraphToVector(Circular cir)
    {
        v_cir.addElement(cir);
    }

    Regular_Pentagon reg = new Regular_Pentagon(0,0,0,0,Color.RED);
    Vector<Regular_Pentagon> v_reg = new Vector<Regular_Pentagon>();
    public void AddGraphToVector(Regular_Pentagon reg)
    {
        v_reg.addElement(reg);
    }

    Square squ = new Square(0,0,0,0,Color.RED);
    Vector<Square> v_squ = new Vector<Square>();
    public void AddGraphToVector(Square squ)
    {
        v_squ.addElement(squ);
    }

    Triangle tri = new Triangle(0,0,0,0,Color.RED);
    Vector<Triangle> v_tri = new Vector<Triangle>();
    public void AddGraphToVector(Triangle tri)
    {
        v_tri.addElement(tri);
    }

    string str = new string("LOVE",0,0);
    Vector<string> v_str_cir = new Vector<string>();
    Vector<string> v_str_reg = new Vector<string>();
    Vector<string> v_str_squ = new Vector<string>();
    Vector<string> v_str_tri = new Vector<string>();
    public void AddStringToVector(Circular c, string s)
    {
        v_str_cir.addElement(s);
    }
    public void AddStringToVector(Regular_Pentagon r, string s)
    {
        v_str_reg.addElement(s);
    }
    public void AddStringToVector(Square sq, string s)
    {
        v_str_squ.addElement(s);
    }
    public void AddStringToVector(Triangle t, string s)
    {
        v_str_tri.addElement(s);
    }

    // Declare an instance of the drawing canvas,
    // which is an inner class called DrawCanvas extending javax.swing.JPanel.
    /*
     *画图板
     */
    private DrawCanvas canvas;
    private class DrawCanvas extends JPanel 
    {
        public DrawCanvas()
        {

            AddGraphToVector(cir);
            AddGraphToVector(reg);
            AddGraphToVector(squ);
            AddGraphToVector(tri);
            AddStringToVector(cir,str);
            AddStringToVector(reg,str);
            AddStringToVector(squ,str);
            AddStringToVector(tri,str);
        }
        // Override paintComponent to perform your own painting
        @Override
        public void paintComponent(Graphics g) 
        {
            super.paintComponent(g);     // paint parent's background
            setBackground(Color.white);  // set background color for this JPanel

            //cir.paint(g);
            for (Circular c : v_cir)
            {
                c.paint(g);
            }

            //reg.paint(g);
            // Draw Regular_Pentagon
            for (Regular_Pentagon r : v_reg)
            {
                Polygon p = new Polygon();
                for (int i = 0; i < 5; i++)
                  p.addPoint((int) (r.x + r.width * Math.cos(i * 2 * Math.PI / 5)),
                      (int) (r.y + r.width * Math.sin(i * 2 * Math.PI / 5))); //100 是坐标，90是大小

                g.setColor(r.color);
                g.drawPolygon(p);

            }

            //Draw Square
            for (Square s : v_squ)
            {
                s.paint(g);
            }

            //tri.paint(g);
            //Draw Triangle
            for (Triangle t : v_tri)
            {
                int x0 = (int)t.x; 
                int y0 = (int)(t.y - t.a * 2 / 3);
                int x1 = (int)(t.x + t.a / 2);
                int y1 = (int)(t.y + t.a * 1 / 3);
                int x2 = (int)(t.x - t.a / 2);
                int y2 = (int)(t.y + t.a * 1 / 3);
                g.setColor(t.color);
                g.drawLine(x0, y0, x1, y1);
                g.drawLine(x1, y1, x2, y2);
                g.drawLine(x2, y2, x0, y0);

            }

            //Draw string
            for (string s : v_str_cir)
            {
                s.paint(g);
            }
            for (string s : v_str_reg)
            {
                s.paint(g);
            }
            for (string s : v_str_squ)
            {
                s.paint(g);
            }
            for (string s : v_str_tri)
            {
                s.paint(g);
            }
        }
    }


    /*
     *显示输入框
     */
    public void ShowText()
    {
        JFrame app_text = new JFrame("input");

        //show clean
        app_text.setUndecorated(true);
        app_text.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        app_text.setSize(650,140);
        app_text.setLocationRelativeTo(null);  // center the application window
        //app_text.setLocation(0,0);
        Container c = app_text.getContentPane();
        c.setLayout(new FlowLayout());
       
            // 添加控件
            JTextField[][] text = {{new JTextField("Circular",10), new JTextField("r",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("Reg",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("squ",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("tri",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)}};
            text[0][0].setEditable(false);
            text[1][0].setEditable(false);
            text[2][0].setEditable(false);
            text[3][0].setEditable(false);
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    c.add(text[i][j]); 
                }
            }

        // 添加两个按钮
        JButton[] b = {new JButton("OK"),new JButton("Cancel")};
        c.add(b[0]);
        c.add(b[1]);

        //paint Circular
        // r text event when get focuse set text
        text[0][1].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][1].setText("");
            }
        });
        // x text event when get focuse set text
        text[0][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][2].setText("");
            }
        });
        // y text event when get focuse set text
        text[0][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][3].setText("");
            }
        });
        // color text event
        text[0][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                Circular tmp_cir = new Circular(0,0,0,0,Color.RED);
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_cir.color = color;
                text[0][4].setBackground(color);
                    String s_r = text[0][1].getText();
                    tmp_cir.width = Integer.parseInt(s_r);
                    tmp_cir.height = tmp_cir.width;
                    tmp_cir.r = tmp_cir.width / 2;
                    String s_x = text[0][2].getText();
                    tmp_cir.x = Integer.parseInt(s_x);
                    String s_y = text[0][3].getText();
                    tmp_cir.y = Integer.parseInt(s_y);
                    String s_coloer = text[0][4].getText();

                    tmp_cir.calc_area();
                    tmp_cir.calc_perimeter();

                    int index_string = v_cir.size(); // string 的编号
                    string tmp_str = new string("",0,0);
                    tmp_str.s = index_string + ": area is " + Double.toString(tmp_cir.area) + " per is " + Double.toString(tmp_cir.perimeter);
                    tmp_str.x = tmp_cir.x;
                    tmp_str.y = tmp_cir.y;
                    tmp_str.color = color;
                    AddStringToVector(tmp_cir,tmp_str);
                    AddGraphToVector(tmp_cir);
                    app_text.toFront();
            }
        });

        // paint Regular_Pentagon
        // r text event when get focuse set text
        text[1][1].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[1][1].setText("");
            }
        });
        // x text event when get focuse set text
        text[1][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[1][2].setText("");
            }
        });
        // y text event when get focuse set text
        text[1][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[1][3].setText("");
            }
        });
        // color text event
        text[1][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                Regular_Pentagon tmp_reg = new Regular_Pentagon(0,0,0,0,Color.RED);
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_reg.color = color;
                text[1][4].setBackground(color);
                    String s_r = text[1][1].getText();
                    tmp_reg.width = Integer.parseInt(s_r);
                    tmp_reg.height = tmp_reg.width;
                    tmp_reg.n = tmp_reg.width / 2;
                    String s_x = text[1][2].getText();
                    tmp_reg.x = Integer.parseInt(s_x);
                    String s_y = text[1][3].getText();
                    tmp_reg.y = Integer.parseInt(s_y);
                    String s_coloer = text[1][4].getText();
                    canvas.repaint(0,0,0,0);

                    tmp_reg.calc_area();
                    tmp_reg.calc_perimeter();

                    int index_string = v_reg.size(); // string 的编号
                    string tmp_str = new string("",0,0);
                    tmp_str.s = index_string + ": area is " + Double.toString(tmp_reg.area) + " per is " + Double.toString(tmp_reg.perimeter);
                    tmp_str.x = tmp_reg.x;
                    tmp_str.y = tmp_reg.y;
                    tmp_str.color = color;
                    AddStringToVector(tmp_reg,tmp_str);
                    AddGraphToVector(tmp_reg);
                    app_text.toFront();
            }
        });

        // paint Square 
        // r text event when get focuse set text
        text[2][1].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[2][1].setText("");
            }
        });
        // x text event when get focuse set text
        text[2][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[2][2].setText("");
            }
        });
        // y text event when get focuse set text
        text[2][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[2][3].setText("");
            }
        });
        // color text event
        text[2][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                Square tmp_squ = new Square(0,0,0,0,Color.RED);
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_squ.color = color;
                text[2][4].setBackground(color);
                    String s_r = text[2][1].getText();
                    tmp_squ.width = Integer.parseInt(s_r);
                    tmp_squ.height = tmp_squ.width;
                    tmp_squ.n = tmp_squ.width / 2;
                    String s_x = text[2][2].getText();
                    tmp_squ.x = Integer.parseInt(s_x);
                    String s_y = text[2][3].getText();
                    tmp_squ.y = Integer.parseInt(s_y);
                    String s_coloer = text[2][4].getText();
                    canvas.repaint(0,0,0,0);

                    tmp_squ.calc_area();
                    tmp_squ.calc_perimeter();

                    int index_string = v_squ.size(); // string 的编号
                    string tmp_str = new string("",0,0);
                    tmp_str.s = index_string + ": area is " + Double.toString(tmp_squ.area) + " per is " + Double.toString(tmp_squ.perimeter);
                    tmp_str.x = tmp_squ.x;
                    tmp_str.y = tmp_squ.y;
                    tmp_str.color = color;
                    AddStringToVector(tmp_squ,tmp_str);
                    AddGraphToVector(tmp_squ);
                    app_text.toFront();
            }
        });
        
        // paint Triangle
        // r text event when get focuse set text
        text[3][1].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[3][1].setText("");
            }
        });
        // x text event when get focuse set text
        text[3][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[3][2].setText("");
            }
        });
        // y text event when get focuse set text
        text[3][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[3][3].setText("");
            }
        });
        // color text event
        text[3][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                Triangle tmp_tri = new Triangle(0,0,0,0,Color.RED);
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_tri.color = color;
                text[3][4].setBackground(color);
                    String s_r = text[3][1].getText();
                    tmp_tri.width = Integer.parseInt(s_r);
                    tmp_tri.height = tmp_tri.width;
                    tmp_tri.a = tmp_tri.width / 2;
                    String s_x = text[3][2].getText();
                    tmp_tri.x = Integer.parseInt(s_x);
                    String s_y = text[3][3].getText();
                    tmp_tri.y = Integer.parseInt(s_y);
                    String s_coloer = text[3][4].getText();
                    canvas.repaint(0,0,0,0);

                    tmp_tri.calc_area();
                    tmp_tri.calc_perimeter();

                    int index_string = v_tri.size(); // string 的编号
                    string tmp_str = new string("",0,0);
                    tmp_str.s = index_string + ": area is " + Double.toString(tmp_tri.area) + " per is " + Double.toString(tmp_tri.perimeter);
                    tmp_str.x = tmp_tri.x;
                    tmp_str.y = tmp_tri.y;
                    tmp_str.color = color;
                    AddStringToVector(tmp_tri,tmp_str);
                    AddGraphToVector(tmp_tri);
                    app_text.toFront();
            }
        });

        //Cancel event
        b[1].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    app_text.dispose(); //close frame
                }
            }
        );


        //OK event
        b[0].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    canvas.repaint();

                    app_text.dispose(); //close frame
                }
            }
        );
        app_text.setVisible(true);
    }

    public my_frame()
    {

        super("paint");
        
        JFrame frame = new JFrame();
        JMenuBar bar = new JMenuBar();
        setJMenuBar(bar);
        //add menu
        JMenu[] m = { new JMenu("Menu")};
        JMenuItem[] m_t = {new JMenuItem("Add"),new JMenuItem("Delete"),new JMenuItem("Modify")};
        bar.add(m[0]);
        frame.setJMenuBar(bar);

        for (int i = 0; i < m_t.length; i++)
        {
            m[0].add(m_t[i]);
        }

            //Add event
            m_t[0].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                        ShowText();
                    }
                }
            );
            
            //Delete event
            m_t[1].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                    }
                }
            );

            //Modify event
            m_t[2].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                    }
                }
            );

 

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GetScreenSize();
        frame.setSize(max_size_width,max_size_hight);
        frame.setVisible(true);

        Container c = frame.getContentPane();
        c.setLayout(new FlowLayout());

        /*
         *添加画板
         */
        canvas = new DrawCanvas();    // Construct the drawing canvas
        canvas.setPreferredSize(new Dimension(frame.getWidth(), frame.getHeight()));
        c.add(canvas);

    }
}

