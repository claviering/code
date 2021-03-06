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
 * |____ AddGraph() 点击菜单触发函数
 * |____ my_frame() 构造函数，显示图形界面
 */

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.*;
import javax.swing.UIManager.LookAndFeelInfo;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;

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

    // Declare an instance of the drawing canvas,
    // which is an inner class called DrawCanvas extending javax.swing.JPanel.
    /*
     *画图板
     */
    private DrawCanvas canvas;
    private class DrawCanvas extends JPanel 
    {
        private BufferedImage paintImage = new BufferedImage(max_size_width, max_size_hight, BufferedImage.TYPE_INT_RGB);

        boolean is_load_file = false;

        public DrawCanvas()
        {

            AddGraphToVector(cir);
            AddGraphToVector(reg);
            AddGraphToVector(squ);
            AddGraphToVector(tri);
        }
        // Override paintComponent to perform your own painting
        @Override
        public void paintComponent(Graphics g) 
        {
            super.paintComponent(g);     // paint parent's background
            setBackground(Color.white);  // set background color for this JPanel
            if (is_load_file)
            {
                g.drawImage(paintImage, 0, 0, this);
                is_load_file = false;
            }


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

        }
        
        // draw painting
        public void updatepaint()
        {
            Graphics g = paintImage.createGraphics();
            g.dispose();
            repaint();
        }

        public void save() throws IOException
        {
            canvas.print(paintImage.getGraphics());
            ImageIO.write(paintImage, "PNG", new File("filename.png"));
        }

        public void load() throws IOException
        {
            is_load_file = true;
            paintImage = ImageIO.read(new File("filename.png"));
            repaint();
        }
    }


    /*
     *显示输入框
     */
    JFrame app_text = new JFrame("input");
    // 添加Add控件
    JTextField[][] text = {{new JTextField("Cir",10), new JTextField("r",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("Reg",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("squ",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)},{new JTextField("tri",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)}};
    JButton[] b_color = {new JButton("ADD"),new JButton("ADD"),new JButton("ADD"),new JButton("ADD")};
    JButton b = new JButton("OK");

    // get Cir r x y color
    public void GetCirTextFileContent()
    {
                Circular tmp_cir = new Circular(0,0,0,0,Color.RED);
                String s_r = text[0][1].getText();
                String s_x = text[0][2].getText();
                String s_y = text[0][3].getText();
                tmp_cir.width = Integer.parseInt(s_r);
                tmp_cir.height = tmp_cir.width;
                tmp_cir.r = tmp_cir.width / 2;
                tmp_cir.x = Integer.parseInt(s_x);
                tmp_cir.y = Integer.parseInt(s_y);
                for (Circular c : v_cir)
                {
                    if (c.x == tmp_cir.x && c.y == tmp_cir.y && c.r == tmp_cir.r)
                        return;
                }
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_cir.color = color;
                text[0][4].setBackground(color);

                    string tmp_str = new string("",0,0);
                    tmp_str.s = ": area is " + Double.toString(tmp_cir.area) + " per is " + Double.toString(tmp_cir.perimeter);
                    tmp_str.x = tmp_cir.x;
                    tmp_str.y = tmp_cir.y;
                    tmp_str.color = color;
                    AddGraphToVector(tmp_cir);
                    String tmp_String = "cir r:" + s_r + " " + "x:" + s_x + " " + "y:" + s_y;
                    v_delete_cir.addElement(tmp_String);
                    app_text.toFront();
    }

    // get reg r x y color
    public void GetRegTextFileContent()
    {
                Regular_Pentagon tmp_reg = new Regular_Pentagon(0,0,0,0,Color.RED);
                String s_r = text[1][1].getText();
                String s_x = text[1][2].getText();
                String s_y = text[1][3].getText();
                String s_coloer = text[1][4].getText();
                tmp_reg.width = Integer.parseInt(s_r);
                tmp_reg.height = tmp_reg.width;
                tmp_reg.n = tmp_reg.width / 2;
                tmp_reg.x = Integer.parseInt(s_x);
                tmp_reg.y = Integer.parseInt(s_y);
                for (Regular_Pentagon r : v_reg)
                {
                    if (r.x == tmp_reg.x && r.y == tmp_reg.y && r.n == tmp_reg.n)
                        return;
                }
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_reg.color = color;
                text[1][4].setBackground(color);

                    string tmp_str = new string("",0,0);
                    tmp_str.s = ": area is " + Double.toString(tmp_reg.area) + " per is " + Double.toString(tmp_reg.perimeter);
                    tmp_str.x = tmp_reg.x;
                    tmp_str.y = tmp_reg.y;
                    tmp_str.color = color;
                    AddGraphToVector(tmp_reg);
                    String tmp_String = "reg r:" + s_r + " " + "x:" + s_x + " " + "y:" + s_y;
                    v_delete_reg.addElement(tmp_String);
                    app_text.toFront();

    }

    // get squ r x y color
    public void GetSquTextFileContent()
    {
                Square tmp_squ = new Square(0,0,0,0,Color.RED);
                String s_r = text[2][1].getText();
                String s_x = text[2][2].getText();
                String s_y = text[2][3].getText();
                String s_coloer = text[2][4].getText();
                tmp_squ.width = Integer.parseInt(s_r);
                tmp_squ.height = tmp_squ.width;
                tmp_squ.n = tmp_squ.width / 2;
                tmp_squ.x = Integer.parseInt(s_x);
                tmp_squ.y = Integer.parseInt(s_y);
                for (Square s : v_squ)
                {
                    if (s.x == tmp_squ.x && s.y == tmp_squ.y && s.n == tmp_squ.n)
                        return;
                }
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_squ.color = color;
                text[2][4].setBackground(color);

                    string tmp_str = new string("",0,0);
                    tmp_str.s = ": area is " + Double.toString(tmp_squ.area) + " per is " + Double.toString(tmp_squ.perimeter);
                    tmp_str.x = tmp_squ.x;
                    tmp_str.y = tmp_squ.y;
                    tmp_str.color = color;
                    AddGraphToVector(tmp_squ);
                    String tmp_String = "squ r:" + s_r + " " + "x:" + s_x + " " + "y:" + s_y;
                    v_delete_squ.addElement(tmp_String);
                    app_text.toFront();

    }
    // get tri r x y color
    public void GetTriTextFileContent()
    {
                Triangle tmp_tri = new Triangle(0,0,0,0,Color.RED);
                String s_r = text[3][1].getText();
                String s_x = text[3][2].getText();
                String s_y = text[3][3].getText();
                String s_coloer = text[3][4].getText();
                tmp_tri.width = Integer.parseInt(s_r);
                tmp_tri.height = tmp_tri.width;
                tmp_tri.a = tmp_tri.width / 2;
                tmp_tri.b = tmp_tri.width / 2;
                tmp_tri.c = tmp_tri.width / 2;
                tmp_tri.x = Integer.parseInt(s_x);
                tmp_tri.y = Integer.parseInt(s_y);
                for (Triangle t : v_tri)
                {
                    if (t.x == tmp_tri.x && t.y == tmp_tri.y && t.a == tmp_tri.a)
                        return;
                }
                Color color = JColorChooser.showDialog(null, "Choose a color", Color.LIGHT_GRAY);
                tmp_tri.color = color;
                text[3][4].setBackground(color);

                    string tmp_str = new string("",0,0);
                    tmp_str.s = ": area is " + Double.toString(tmp_tri.area) + " per is " + Double.toString(tmp_tri.perimeter);
                    tmp_str.x = tmp_tri.x;
                    tmp_str.y = tmp_tri.y;
                    tmp_str.color = color;
                    AddGraphToVector(tmp_tri);
                    String tmp_String = "tri r:" + s_r + " " + "x:" + s_x + " " + "y:" + s_y;
                    v_delete_tri.addElement(tmp_String);
                    app_text.toFront();

    }

    public void AddGraph()
    {

        //show clean
        app_text.setUndecorated(true);
        app_text.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        app_text.setSize(700,160);
        app_text.setLocationRelativeTo(null);  // center the application window
        Container c = app_text.getContentPane();
        app_text.setVisible(true);
        c.setLayout(new FlowLayout());

        for (int i = 0; i < 4; i++)
        {
            text[i][0].setEditable(false);
        }
       
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                c.add(text[i][j]); 
            }
            c.add(b_color[i]);
        }

        // 添加两个按钮,cancel按钮没用了，按ok就关闭
        c.add(b);

        //paint Circular
        // r text event when get focuse set text
        text[0][1].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][1].setText("");
            }
        });
        // cir x text event when get focuse set text
        text[0][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][2].setText("");
            }
        });
        // cir y text event when get focuse set text
        text[0][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[0][3].setText("");
            }
        });
        // cir color text event
        text[0][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                GetCirTextFileContent();
            }
        });
        text[0][4].addKeyListener(new java.awt.event.KeyAdapter()
        {
            public void keyPressed(java.awt.event.KeyEvent evt) 
            {
                GetCirTextFileContent();
            }
        });
        // cir ADD event
        b_color[0].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                text[0][4].setBackground(null);
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
        // reg x text event when get focuse set text
        text[1][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[1][2].setText("");
            }
        });
        // reg y text event when get focuse set text
        text[1][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[1][3].setText("");
            }
        });
        // reg color text event
        text[1][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                GetRegTextFileContent();
            }
        });
        text[1][4].addKeyListener(new java.awt.event.KeyAdapter()
        {
            public void keyPressed(java.awt.event.KeyEvent evt) 
            {
                GetRegTextFileContent();
            }
        });
        // reg ADD event
        b_color[1].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                text[1][4].setBackground(null);
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
        // squ x text event when get focuse set text
        text[2][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[2][2].setText("");
            }
        });
        // squ y text event when get focuse set text
        text[2][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[2][3].setText("");
            }
        });
        // squ color text event
        text[2][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                GetSquTextFileContent();
            }
        });
        text[2][4].addKeyListener(new java.awt.event.KeyAdapter()
        {
            public void keyPressed(java.awt.event.KeyEvent evt) 
            {
                GetSquTextFileContent();
            }
        });
        // squ ADD event
        b_color[2].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                text[2][4].setBackground(null);
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
        // tri x text event when get focuse set text
        text[3][2].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[3][2].setText("");
            }
        });
        // tri y text event when get focuse set text
        text[3][3].addFocusListener(new java.awt.event.FocusAdapter() 
        {
            public void focusGained(java.awt.event.FocusEvent evt) 
            {
                text[3][3].setText("");
            }
        });
        // tri color text event
        text[3][4].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                GetTriTextFileContent();
            }
        });
        text[3][4].addKeyListener(new java.awt.event.KeyAdapter()
        {
            public void keyPressed(java.awt.event.KeyEvent evt) 
            {
                GetTriTextFileContent();
            }
        });
        // tri ADD event
        b_color[3].addMouseListener(new java.awt.event.MouseAdapter() 
        {
            public void mouseClicked(java.awt.event.MouseEvent evt) 
            {
                text[3][4].setBackground(null);
                canvas.repaint();
            }
        });

        //OK event
        b.addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    app_text.dispose(); //close frame
                }
            }
        );
    }



    


    // Modify code below
    JTextField[][] modify_text = 
    {
        {new JTextField("Cir",10), new JTextField("new r",10), new JTextField("new x",10), new JTextField("new y",10), new JTextField("new Color",10)},
        {new JTextField("Reg",10), new JTextField("new n",10), new JTextField("new x",10), new JTextField("new y",10), new JTextField("new Color",10)},
        {new JTextField("squ",10), new JTextField("new n",10), new JTextField("new x",10), new JTextField("new y",10), new JTextField("new Color",10)},
        {new JTextField("tri",10), new JTextField("new n",10), new JTextField("new x",10), new JTextField("new y",10), new JTextField("new Color",10)}
    };

    public void ModifyGraph()
    {
        JOptionPane.showMessageDialog(null, "Delete and Add", "Modify",JOptionPane.INFORMATION_MESSAGE);
    }

    //delete with combox
    JFrame delete_list = new JFrame("DELETE");
    Vector<String> v_delete_cir = new Vector<String>();
    Vector<String> v_delete_reg = new Vector<String>();
    Vector<String> v_delete_squ = new Vector<String>();
    Vector<String> v_delete_tri = new Vector<String>();
    JComboBox[] delete_box = {new JComboBox(v_delete_cir),new JComboBox(v_delete_reg),new JComboBox(v_delete_squ),new JComboBox(v_delete_tri)};
    JButton[] del = {new JButton("DEL"),new JButton("DEL"),new JButton("DEL"),new JButton("DEL")};
    String null_string_in_combox = "                                    ";
    public void Delete()
    {
        delete_list.setUndecorated(true);
        delete_list.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        delete_list.setSize(400,160);
        delete_list.setLocationRelativeTo(null);
        delete_list.setVisible(true);
        Container c = delete_list.getContentPane();
        c.setLayout(new FlowLayout());
        for (int i = 0; i < 4; i++)
        {
            c.add(text[i][0]);
            text[i][0].setEditable(false);
            delete_box[i].addItem("                                    ");
            c.add(delete_box[i]);
            c.add(del[i]);
        }
        c.add(b);
        //OK event
        b.addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    delete_list.dispose(); //close frame
                }
            }
        );
        //cir DEL event
        del[0].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    int selectedIndex = delete_box[0].getSelectedIndex();
                    if (selectedIndex >= 0)
                    {

                        delete_box[0].setSelectedItem(null_string_in_combox);
                        v_cir.remove(selectedIndex + 1);

                        v_delete_cir.remove(selectedIndex);
                        JComboBox tmp = new JComboBox(v_delete_cir);
                        delete_box[0] = tmp;

                        canvas.repaint();
                    }
                }
            }
        );
        //reg DEL event
        del[1].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    int selectedIndex = delete_box[1].getSelectedIndex();
                    if (selectedIndex >= 0)
                    {
                        delete_box[1].setSelectedItem(null_string_in_combox);
                        v_reg.remove(selectedIndex + 1);

                        v_delete_reg.remove(selectedIndex);
                        JComboBox tmp = new JComboBox(v_delete_reg);
                        delete_box[1] = tmp;

                        canvas.repaint();
                    }
                }
            }
        );
        //squ DEL event
        del[2].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    int selectedIndex = delete_box[2].getSelectedIndex();
                    if (selectedIndex >= 0)
                    {
                        delete_box[2].setSelectedItem(null_string_in_combox);
                        v_squ.remove(selectedIndex + 1);

                        v_delete_squ.remove(selectedIndex);
                        JComboBox tmp = new JComboBox(v_delete_squ);
                        delete_box[2] = tmp;

                        canvas.repaint();
                    }
                }
            }
        );
        //tri DEL event
        del[3].addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    int selectedIndex = delete_box[3].getSelectedIndex();
                    if (selectedIndex >= 0)
                    {
                        delete_box[3].setSelectedItem(null_string_in_combox);
                        v_tri.remove(selectedIndex + 1);

                        v_delete_tri.remove(selectedIndex);
                        JComboBox tmp = new JComboBox(v_delete_tri);
                        delete_box[3] = tmp;

                        canvas.repaint();
                    }
                }
            }
        );
    }

    public my_frame()
    {

        super("paint");
        
        JFrame frame = new JFrame();
        JMenuBar bar = new JMenuBar();
        setJMenuBar(bar);
        //add menu
        JMenu[] m = { new JMenu("Menu"), new JMenu("File")};
        JMenuItem[] m_t = {new JMenuItem("Add"),new JMenuItem("Delete"),new JMenuItem("Modify")};
        JMenuItem[] m_file = {new JMenuItem("save"),new JMenuItem("load")};
        bar.add(m[0]);
        bar.add(m[1]);
        frame.setJMenuBar(bar);

        for (int i = 0; i < m_t.length; i++)
        {
            m[0].add(m_t[i]);
        }

        for (int i = 0; i < m_file.length; i++)
        {
            m[1].add(m_file[i]);
        }

            //save event
            m_file[0].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        try
                        {
                            canvas.save();
                            JOptionPane.showMessageDialog(null, "successful", "save",JOptionPane.INFORMATION_MESSAGE);
                        }
                        catch(IOException ee)
                        {
                            ee.printStackTrace();
                        }
                    }
                }
            );
            //load event
            m_file[1].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        try
                        {
                            canvas.load();
                        }
                        catch(IOException ee)
                        {
                            ee.printStackTrace();
                        }
                    }
                }
            );

            //Add event
            m_t[0].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                        AddGraph();
                    }
                }
            );
            
            //Delete event
            m_t[1].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                        Delete();
                    }
                }
            );

            //Modify event
            m_t[2].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                        ModifyGraph();
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

