/********************************************************************
	> File Name: my_frame.java
	> Author: lin 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 05:40:40 PM CST
 *******************************************************************/

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

    Circular cir = new Circular(0,0,0,0,Color.RED);

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

            // Your custom painting codes. For example,
            // Drawing primitive shapes
            /*
             *g.setColor(Color.YELLOW);    // set the drawing color
             *g.drawLine(30, 40, 100, 200);
             *g.drawOval(150, 180, 10, 10);
             *g.drawRect(200, 210, 20, 30);
             *g.setColor(Color.RED);       // change the drawing color
             *g.fillOval(300, 310, 30, 50);
             *g.fillRect(400, 350, 60, 50);
             */
            // Printing texts
            /*
             *g.setColor(Color.WHITE);
             *g.setFont(new Font("Monospaced", Font.PLAIN, 12));
             *g.drawString("Testing custom drawing ...", 10, 20);
             */

            cir.paint(g);
        }
    }

    void DrwaCircular()
    {

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
       
            JTextField[] cir_text = {new JTextField("Circular",10), new JTextField("r",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)};
            cir_text[0].setEditable(false);
            for (int i = 0; i < 5; i++)
            {
                c.add(cir_text[i]); 
            }
            JTextField[] reg_text = {new JTextField("Reg",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)};
            reg_text[0].setEditable(false);
            for (int i = 0; i < 5; i++)
            {
                c.add(reg_text[i]); 
            }
            JTextField[] squ_text = {new JTextField("squ",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)};
            squ_text[0].setEditable(false);
            for (int i = 0; i < 5; i++)
            {
                c.add(squ_text[i]); 
            }
            JTextField[] tri_text = {new JTextField("tri",10), new JTextField("n",10), new JTextField("x",10), new JTextField("y",10), new JTextField("Color",10)};
            tri_text[0].setEditable(false);
            for (int i = 0; i < 5; i++)
            {
                c.add(tri_text[i]); 
            }

        JButton[] b = {new JButton("OK"),new JButton("Cancel")};
        c.add(b[0]);
        c.add(b[1]);

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
                    String s_r = cir_text[1].getText();
                    cir.width = Integer.parseInt(s_r);
                    cir.height = cir.width;
                    String s_x = cir_text[2].getText();
                    cir.x = Integer.parseInt(s_x);
                    String s_y = cir_text[3].getText();
                    cir.y = Integer.parseInt(s_y);
                    String s_coloer = cir_text[4].getText();
                    cir.color = Color.red;
                    canvas.repaint(0,0,0,0);
                    canvas.repaint(cir.x, cir.y, cir.width, cir.height);

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

