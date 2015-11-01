package v2;

import java.util.Vector;

public class Publisher // Klasse abstrakt machen?
{
    private Vector<Observer> lobs; // warum Vector und nicht ArrayList? Synchronisation ohne multithreads?
    
    public Publisher()
    {
        lobs = new Vector<Observer>();
    }
    
    public void attach(Observer no)
    {
        if(!lobs.contains(no))
        {
            lobs.addElement(no);
        }
    }
    
    public void detach(Observer no)
    {
        if(lobs.contains(no))
        {
            lobs.remove(no);
        }
    }
    
    public void inform()
    {
        for (Observer obs : lobs)
        {
            obs.update(this);
        }
    }
}
