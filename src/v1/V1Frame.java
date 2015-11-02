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
    private Container c;
    private JPanel pInputName;
    private JPanel pDisplayNameList;
    private JPanel pOptionButtons;
    private JPanel pButtonCenterBox;

    private JTextField nameInputField;
    private JList<String> nameJList;
    private JButton bLoad;
    private JButton bAdd;
    private JButton bDelete;

    private DefaultListModel<String> defaultList;
    private ArrayList<String> arrayList;                    // bessere Lösung?
    
    public V1Frame(String title)
    {
        super(title);
        c = this.getContentPane();
        
        // initialize Panels
        pInputName = new JPanel(new BorderLayout());
        pDisplayNameList = new JPanel(new BorderLayout());
        pOptionButtons = new JPanel(new GridBagLayout());
        pButtonCenterBox = new JPanel(new GridLayout(1, 3, 30,10));
        
        // initialize components input name panel
        nameInputField = new JTextField();
        
        // add documentListener to input field
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
                private void hasText()
                {
                    if (nameInputField.getText().equals(""))
                    {
                        bAdd.setEnabled(false);
                    }
                    else
                    {
                        bAdd.setEnabled(true);
                    }
                }
            });
        
        // initialize components name list panel
        arrayList = new ArrayList<String>();
        defaultList = new DefaultListModel<String>();
        this.fillListDefaultNames();
        nameJList = new JList<String>(defaultList);
        //nameJList.setVisibleRowCount(10);                                                     // Keine Auswirkung, Fragen im Praktikum? Vllt wegen Layoutmanager?
        nameJList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        nameJList.setBorder(BorderFactory.createLineBorder(new Color(0,0,0)));
        
        // initialize components option button panel
        bLoad = new JButton("Laden");
        bAdd = new JButton("Hinzufügen");
        bAdd.setEnabled(false);
        bDelete = new JButton("Entfernen");
        
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
                    }
                });
        
        bDelete.addActionListener(new ActionListener()
                {
                    public void actionPerformed(ActionEvent deleteEvent)
                    {
                        if (nameJList.isSelectionEmpty())
                        {
                            JOptionPane.showMessageDialog(null, "Bitte wählen Sie zunächst einen Namen zum Entfernen aus der Liste aus.", "Kein Name ausgewählt", JOptionPane.INFORMATION_MESSAGE);
                        }
                        else
                        {
                            if (JOptionPane.showConfirmDialog(null , "Wollen sie die Namensliste wirklich löschen?", "Namens aus liste entfernen", JOptionPane.WARNING_MESSAGE) == JOptionPane.YES_OPTION)
                            {
                                arrayList.remove(nameJList.getSelectedValue());
                                repopulateList();
                            }
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
        arrayList.add("Abel");
        arrayList.add("Galler");
        arrayList.add("Huber");
        arrayList.add("Irber");
        arrayList.add("Kugler");
        arrayList.add("Schuster");
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
        V1Frame f1 = new V1Frame("test");
        f1.setVisible(true);
    }

}
