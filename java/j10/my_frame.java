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
    Regular_Pentagon reg = new Regular_Pentagon(0,0,0,0,Color.RED);
    Square squ = new Square(0,0,0,0,Color.RED);
    Triangle tri = new Triangle(0,0,0,0,Color.RED);
    string str = new string("LOVE",0,0);

    // Declare an instance of the drawing canvas,
    // which is an inner class called DrawCanvas extending javax.swing.JPanel.
    /*
     *画图板
     */
    private DrawCanvas canvas;
    private class DrawCanvas extends JPanel 
    {
        // Override paintComponent to perform your own painting
        @Override
        public void paintComponent(Graphics g) 
        {
            super.paintComponent(g);     // paint parent's background
            setBackground(Color.BLACK);  // set background color for this JPanel

            cir.paint(g);
            //reg.paint(g);
            squ.paint(g);
            //tri.paint(g);
            str.paint(g);

            // Draw Regular_Pentagon
            Polygon p = new Polygon();
            for (int i = 0; i < 5; i++)
              p.addPoint((int) (reg.x + reg.width * Math.cos(i * 2 * Math.PI / 5)),
                  (int) (reg.y + reg.width * Math.sin(i * 2 * Math.PI / 5))); //100 是坐标，90是大小

            g.setColor(reg.color);
            g.drawPolygon(p);

            //Draw Triangle
            int x0 = (int)tri.x; 
            int y0 = (int)(tri.y - tri.a * 2 / 3);
            int x1 = (int)(tri.x + tri.a / 2);
            int y1 = (int)(tri.y + tri.a * 1 / 3);
            int x2 = (int)(tri.x - tri.a / 2);
            int y2 = (int)(tri.y + tri.a * 1 / 3);
            g.setColor(tri.color);
            g.drawLine(x0, y0, x1, y1);
            g.drawLine(x1, y1, x2, y2);
            g.drawLine(x2, y2, x0, y0);
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
        text[0][4].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                cir.color = color;
                    String s_r = text[0][1].getText();
                    cir.width = Integer.parseInt(s_r);
                    cir.height = cir.width;
                    cir.r = cir.width / 2;
                    String s_x = text[0][2].getText();
                    cir.x = Integer.parseInt(s_x);
                    String s_y = text[0][3].getText();
                    cir.y = Integer.parseInt(s_y);
                    String s_coloer = text[0][4].getText();
                    canvas.repaint(cir.x, cir.y, cir.width, cir.height);

                    cir.calc_area();
                    cir.calc_perimeter();

                    str.s = "area is " + Double.toString(cir.area) + " per is " + Double.toString(cir.perimeter);
                    str.x = cir.x;
                    str.y = cir.y;
                    app_text.dispose(); //close frame
                    canvas.repaint();
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
        text[1][4].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                reg.color = color;
                    String s_r = text[1][1].getText();
                    reg.width = Integer.parseInt(s_r);
                    reg.height = reg.width;
                    reg.n = reg.width / 2;
                    String s_x = text[1][2].getText();
                    reg.x = Integer.parseInt(s_x);
                    String s_y = text[1][3].getText();
                    reg.y = Integer.parseInt(s_y);
                    String s_coloer = text[1][4].getText();
                    canvas.repaint(0,0,0,0);
                    canvas.repaint(reg.x, reg.y, reg.width, reg.height);

                    reg.calc_area();
                    reg.calc_perimeter();

                    str.s = "area is " + Double.toString(reg.area) + " per is " + Double.toString(reg.perimeter);
                    str.x = reg.x;
                    str.y = reg.y;
                    app_text.dispose(); //close frame
                    canvas.repaint();
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
        text[2][4].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                squ.color = color;
                    String s_r = text[2][1].getText();
                    squ.width = Integer.parseInt(s_r);
                    squ.height = squ.width;
                    squ.n = squ.width / 2;
                    String s_x = text[2][2].getText();
                    squ.x = Integer.parseInt(s_x);
                    String s_y = text[2][3].getText();
                    squ.y = Integer.parseInt(s_y);
                    String s_coloer = text[2][4].getText();
                    canvas.repaint(0,0,0,0);
                    canvas.repaint(squ.x, squ.y, squ.width, squ.height);

                    squ.calc_area();
                    squ.calc_perimeter();

                    str.s = "area is " + Double.toString(squ.area) + " per is " + Double.toString(squ.perimeter);
                    str.x = squ.x;
                    str.y = squ.y;
                    app_text.dispose(); //close frame
                    canvas.repaint();
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
        text[3][4].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tri.color = color;
                    String s_r = text[3][1].getText();
                    tri.width = Integer.parseInt(s_r);
                    tri.height = tri.width;
                    tri.a = tri.width / 2;
                    String s_x = text[3][2].getText();
                    tri.x = Integer.parseInt(s_x);
                    String s_y = text[3][3].getText();
                    tri.y = Integer.parseInt(s_y);
                    String s_coloer = text[3][4].getText();
                    canvas.repaint(0,0,0,0);
                    canvas.repaint(tri.x, tri.y, tri.width, tri.height);

                    tri.calc_area();
                    tri.calc_perimeter();

                    str.s = "area is " + Double.toString(tri.area) + " per is " + Double.toString(tri.perimeter);
                    str.x = tri.x;
                    str.y = tri.y;
                    app_text.dispose(); //close frame
                    canvas.repaint();
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
                    String s_r = text[0][1].getText();
                    cir.width = Integer.parseInt(s_r);
                    cir.height = cir.width;
                    cir.r = cir.width / 2;
                    String s_x = text[0][2].getText();
                    cir.x = Integer.parseInt(s_x);
                    String s_y = text[0][3].getText();
                    cir.y = Integer.parseInt(s_y);
                    String s_coloer = text[0][4].getText();
                    canvas.repaint(0,0,0,0);
                    canvas.repaint(cir.x, cir.y, cir.width, cir.height);

                    cir.calc_area();
                    cir.calc_perimeter();

                    str.s = "area is " + Double.toString(cir.area) + " per is " + Double.toString(cir.perimeter);
                    str.x = cir.x;
                    str.y = cir.y;
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

