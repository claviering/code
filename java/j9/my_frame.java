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

    // Define constants
    public static final int CANVAS_WIDTH  = 640;
    public static final int CANVAS_HEIGHT = 480;

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
            g.setColor(Color.YELLOW);    // set the drawing color
            g.drawLine(30, 40, 100, 200);
            g.drawOval(150, 180, 10, 10);
            g.drawRect(200, 210, 20, 30);
            g.setColor(Color.RED);       // change the drawing color
            g.fillOval(300, 310, 30, 50);
            g.fillRect(400, 350, 60, 50);
            // Printing texts
            g.setColor(Color.WHITE);
            g.setFont(new Font("Monospaced", Font.PLAIN, 12));
            g.drawString("Testing custom drawing ...", 10, 20);
        }
    }


    /*
     *显示输入框
     */
    public void ShowText()
    {
        JFrame app_text = new JFrame("input r");

        //show clean
        app_text.setUndecorated(true);
        app_text.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        app_text.setSize(400,80);
        app_text.setLocation(0,0);
        Container c = app_text.getContentPane();
        c.setLayout(new FlowLayout());

        JTextField[] text = {new JTextField("input r",10), new JTextField("0",10)};
        text[0].setEditable(false);
        c.add(text[0]); //only text
        c.add(text[1]); //input r

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
                    String s = text[1].getText();
                    System.out.println(s);
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

            m_t[i].addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        JMenuItem m = (JMenuItem)e.getSource();
                        ShowText();
                    }
                }
            );
        }

 

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        GetScreenSize();
        frame.setSize(max_size_width,max_size_hight);
        frame.setVisible(true);

        Container c = frame.getContentPane();
        c.setLayout(new FlowLayout());
        JButton b = new JButton("love");
        b.setLocation(100,100);
        c.add(b);
        //love event
        b.addActionListener(new ActionListener()
            {
                public void actionPerformed(ActionEvent e)
                {
                    System.out.println("love");
                }
            }
        );

        /*
         *添加画板
         */
        canvas = new DrawCanvas();    // Construct the drawing canvas
        canvas.setPreferredSize(new Dimension(frame.getWidth(), CANVAS_HEIGHT));
        c.add(canvas);

    }
}

