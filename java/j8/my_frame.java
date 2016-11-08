/********************************************************************
	> File Name: my_frame.java
	> Author: lin 
	> Mail: 
	> Created Time: Mon 07 Nov 2016 05:40:40 PM CST
 *******************************************************************/

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
import java.applet.*;


public class my_frame extends JFrame
{

    public void ShowText()
    {
        JFrame app_text = new JFrame("input r");

        //show clean
        app_text.setUndecorated(true);
        app_text.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        app_text.setSize(400,40);
        app_text.setLocation(10,80);
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

        frame.setJMenuBar(bar);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(450,278);
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

    }
}

