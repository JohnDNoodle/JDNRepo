package v2;

public class AverageObserver implements Observer
{
    private int anz;
    private int cnt;
    private float[] blk;
    private PubDataRecorder pdr; // überhaupt nötig? wird nciht benutzt
    
    public AverageObserver(PubDataRecorder rec, int len)
    {
        anz = len;
        pdr = rec;
        cnt = 0;
        blk = new float[anz];
    }
    
    @Override
    public void update(Publisher pub) 
    {
        cnt++;
        if (cnt >=5) // größer gleich falls cnt > anz um endlosschleife abzufangen?
        {
            blk = ((PubDataRecorder)pub).getBlock(anz);
            System.out.println("Mittelwert: " + compAverage());
            cnt = 0;
        }
        
    }
    
    private float compAverage()
    {
        float avg = 0.0f;
        for (float mw : blk)
        {
            avg += mw;
        }        
        return (avg/anz);
    }

}
