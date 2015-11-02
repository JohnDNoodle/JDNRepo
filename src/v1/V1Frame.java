package v1;

import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.*;
import javax.swing.event.*;

@SuppressWarnings("serial")
public class V1Frame extends JFrame
{

    private DefaultListModel<String> defaultList;
    private ArrayList<String> arrayList;                    // bessere Lösung?
    private static final String[] defaultNames= {"Abel", "Galler", "Huber", "Irber", "Kugler", "Schuster"};
    
    public V1Frame(String title)
    {
        super(title);

        Container c;
        JPanel pInputName;
        JPanel pDisplayNameList;
        JPanel pOptionButtons;
        JPanel pButtonCenterBox;

        JTextField nameInputField;
        JList<String> nameJList;
        JButton bLoad;
        JButton bDelete;
        JButton bAdd;
        
        c = this.getContentPane();
        
        // initialize Panels
        pInputName = new JPanel(new BorderLayout());
        pDisplayNameList = new JPanel(new BorderLayout());
        pOptionButtons = new JPanel(new GridBagLayout());
        pButtonCenterBox = new JPanel(new GridLayout(1, 3, 30,10));
        
        // initialize components input name panel
        nameInputField = new JTextField();
        
        // add documentListener to input field
       
        
        // initialize components name list panel
        arrayList = new ArrayList<String>();
        defaultList = new DefaultListModel<String>();
        this.fillListDefaultNames();
        nameJList = new JList<String>(defaultList);
        nameJList.setVisibleRowCount(10);                                                     // Keine Auswirkung, Fragen im Praktikum? Vllt wegen Layoutmanager?
        nameJList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        nameJList.setBorder(BorderFactory.createLineBorder(new Color(0,0,0)));
        
        // initialize components option button panel
        bLoad = new JButton("Laden");
        bLoad.setMnemonic(KeyEvent.VK_L);
        bAdd = new JButton("Hinzufügen");
        bAdd.setMnemonic(KeyEvent.VK_H);
        bAdd.setEnabled(false);
        bDelete = new JButton("Entfernen");
        bDelete.setMnemonic(KeyEvent.VK_E);
        bDelete.setEnabled(false);
        
        // add action listener to buttons
        bLoad.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent loadEvent)
                    {
                        if (JOptionPane.showConfirmDialog(null , "Wollen sie die Namensliste wirklich löschen?", "Namensliste löschen", JOptionPane.WARNING_MESSAGE)== JOptionPane.YES_OPTION)
                        {
                            fillListDefaultNames();
                        }
                    }
                });
        bAdd.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent addEvent)
                    {
                        String newName = nameInputField.getText().trim();
                        if(!arrayList.contains(newName))
                        {
                            arrayList.add(newName);
                            Collections.sort(arrayList);
                            repopulateList();
                        }
                        else
                        {
                        	JOptionPane.showMessageDialog(null , "Der Name existiert bereits.", "Name existiert", JOptionPane.WARNING_MESSAGE);
                        }
                    }
                });
        
        nameInputField.getDocument().addDocumentListener(new DocumentListener()
        {
            public void changedUpdate(DocumentEvent textEvent)
            {
                hasText();
            }
            public void removeUpdate(DocumentEvent textEvent)
            {
                hasText();
            }
            public void insertUpdate(DocumentEvent textEvent)
            {
                hasText();
            }
            public void hasText()
            {
                if (bAdd!=null && nameInputField.getText().trim().isEmpty())
                {
               		bAdd.setEnabled(false);
                }
                else
                {
               		bAdd.setEnabled(true);
                }
            }
        });
        
        bDelete.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent deleteEvent)
                    {
                        
                        if (JOptionPane.showConfirmDialog(null , "Wollen sie die Namensliste wirklich löschen?", "Namens aus liste entfernen", JOptionPane.WARNING_MESSAGE) == JOptionPane.YES_OPTION)
                        {
                            arrayList.remove(nameJList.getSelectedValue());
                            repopulateList();
                        }
                    }
                });
        nameJList.addListSelectionListener(new ListSelectionListener()
		        {

					@Override
					public void valueChanged(ListSelectionEvent selectedName) 
					{
							if (!nameJList.isSelectionEmpty())
							{
								bDelete.setEnabled(true);
							}
							else
							{
								bDelete.setEnabled(false);
							}
					}
		        	
		        });
        
        
        
        // add components to input name panel
        pInputName.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        pInputName.add(new JLabel("Eingabefeld", SwingConstants.LEFT), BorderLayout.NORTH);
        pInputName.add(nameInputField,BorderLayout.SOUTH);
        
        // add components to name list panel
        pDisplayNameList.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        pDisplayNameList.add(new JLabel("Liste", SwingConstants.LEFT), BorderLayout.NORTH);
        pDisplayNameList.add(nameJList, BorderLayout.CENTER);
        
        // add components to option button panel
        pOptionButtons.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        GridBagConstraints gbConstraints = new GridBagConstraints();
        gbConstraints.anchor = GridBagConstraints.CENTER;
        pButtonCenterBox.add(bLoad);
        pButtonCenterBox.add(bAdd);
        pButtonCenterBox.add(bDelete);
        pOptionButtons.add(pButtonCenterBox, gbConstraints);
        

        
        // add components to content pane
        c.add(pInputName, BorderLayout.NORTH);
        c.add(pDisplayNameList, BorderLayout.CENTER);
        c.add(pOptionButtons, BorderLayout.SOUTH);

        this.pack();
        this.setMinimumSize(this.getSize());
        this.setLocationRelativeTo(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    private void fillListDefaultNames()
    {
        arrayList.clear();
        for (String name : defaultNames)
        {
        	arrayList.add(name);
        }
        this.repopulateList();
    }
    private void repopulateList()
    {
        defaultList.clear();
        for(String item : arrayList)
        {
            defaultList.addElement(item);
        }
    }
    
    public static void main(String[] args) 
    {
    	SwingUtilities.invokeLater(new Runnable()
		    	{
    				@Override
		    		public void run()
		    		{
		    			V1Frame f1 = new V1Frame("Versuch1");
		    			f1.setVisible(true);
		    		}
		    	});

    }

}
