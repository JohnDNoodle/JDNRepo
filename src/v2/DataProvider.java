package v2;

import java.util.Random;

public class DataProvider 
{
    private float min;
    private float max;
    private Random randgen;
    
    public DataProvider(float low, float high)
    {
        min = low;
        max = high;
        randgen = new Random();
    }
    
    public float data()
    {
        return (min + (max - min) * randgen.nextFloat());
    }
    
    public static void main(String[] args) 
    {
        System.out.println("Testcase 1: negative minimum");
        DataProvider dat1 = new DataProvider(-5.0f, 5.0f); // Testing if negative min also works.
        for (int i = 0; i < 10; i++)
        {
            System.out.println(dat1.data());
        }
        
        System.out.println("Testcase 2: minimum smaller than max");
        DataProvider dat2 = new DataProvider(5.0f, -5.0f); // Testing if swapping min and max also works.
        for (int i = 0; i < 10; i++)
        {
            System.out.println(dat2.data());
        }
        
    }

}
