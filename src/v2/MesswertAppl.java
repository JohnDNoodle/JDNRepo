package v2;

import java.io.*;

public class MesswertAppl
{
  private DataRecorder     drec;
  private PubDataRecorder  pdr;
  private DataProvider     sensor;
  private AverageObserver  avobsrv;
  private MaxLimitObserver mlobsrv;
	
  public MesswertAppl(int memsize,int blksize,float limit, float min, float max)
  { drec  = new DataRecorder(memsize);
    pdr    = new PubDataRecorder(drec);
    sensor = new DataProvider(min, max);
    mlobsrv = new MaxLimitObserver(pdr, limit);
    avobsrv = new AverageObserver(pdr, blksize);
    pdr.attach(mlobsrv);
    pdr.attach(avobsrv);
  }
	
  public void messen() throws IOException
  {	float val;
    int input;
    System.out.println("Start Messung !");
	while ((input =System.in.read())!=-1)     //RET-Taste  CTRL-Z liefert -1
	{ 
		if(input =='\n'){  // LF
		  val = sensor.data();
		  System.out.println(val);
		  pdr.record(val);
		}
	}	
  }
	
  public static void main(String[] args)
  {	MesswertAppl mwa = new MesswertAppl(20, 5, 15.0f, 5.0f, 20.0f);
    try {
		mwa.messen();
	} catch (IOException e) {
		e.printStackTrace();
	}
  } 
}



