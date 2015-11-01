package v2;

public class PubDataRecorder extends Publisher 
{
    private DataRecorder dr;
    
    public PubDataRecorder(DataRecorder rec)
    {
        dr = rec;
    }
    
    public void record(float mw)
    {
        dr.record(mw);
        this.inform();
    }
    
    public float getLast()
    {
        return dr.getLast();
    }
    
    public float[] getBlock(int anz)
    {
        return dr.getBlock(anz);
    }
}
