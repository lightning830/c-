// Sample4.java
import java.io.*;
public class Sample4
{
        public static void main(String args[])
        {
                int x[];
                System.out.print("input integer: ");
                InputStreamReader isr = new InputStreamReader(System.in);
                BufferedReader br = new BufferedReader(isr);
                String line;
                try{
                    while((line = br.readLine()) != null){
                        String buf[] = line.trim().split(" +");//空白が一回以上で区切る
                        x = new int[buf.length];
                        for(int i=0; i<buf.length; i++){
                            x[i] = Integer.parseInt(buf[i]);
                        }
                    }
                }catch(Exception e){
                    e.getStackTrace();
                }
        }
}