package v2;

public class MaxLimitObserver implements Observer 
{
    private float limit;
    private PubDataRecorder pdr; // überhaupt nötig? wird nicht benutzt
    
    public MaxLimitObserver(PubDataRecorder rec, float grenz)
    {
        pdr = rec;
        limit = grenz;
    }
    
    @Override
    public void update(Publisher pub) 
    {
        if (((PubDataRecorder)pub).getLast() > limit) // pub typecasten oder pdr benutzen?
        {
            System.out.println("Alarm: Messwertueberschreitung");
        }
    }

}
