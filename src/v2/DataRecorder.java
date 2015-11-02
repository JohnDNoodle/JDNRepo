package v2;

public class DataRecorder
{
    private float[] mwarr;
    private int asize;
    private int aktrp;
    
    public DataRecorder(int anz)
    {
        mwarr = new float[anz];
        asize = anz;
        aktrp = 0;
    }
    
    public void record(float mw)  
    {
        mwarr[aktrp] = mw;
        aktrp++;
        aktrp = aktrp % asize;
    }
    
    public float[] getBlock(int anz)
    {
        if (anz > asize)
        {
            anz=asize;
        }
        float[] retMWArray = new float[anz];
        for ( int i = 0; i < anz; i++)
        {
            retMWArray[i] = mwarr[(aktrp + asize - (i + 1))%asize]; // was passiert wenn anz größer asize? sicherheitshalber null zurückgeben.
        }
        return retMWArray;
    }
    
    public float getLast()
    {
        return mwarr[(aktrp + asize - 1)%asize];
    }
    
    public static void main(String[] args)
    {
        DataRecorder rec1 = new DataRecorder(10);
        for (int i = 0; i < 30; i++)
        {
            rec1.record((float)(i+1));
        }
        System.out.println(rec1.getLast());
        float[] arr = rec1.getBlock(5);
        for ( int i = 0; i < 5; i++)
        {
            System.out.println(arr[i]);
        }
        
    }
    
}

