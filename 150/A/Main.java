// Main.java
import java.io.*;
public class Main
{
        public static void main(String args[])
        {
                int K, X;
                InputStreamReader isr = new InputStreamReader(System.in);
                BufferedReader br = new BufferedReader(isr);
                String line;
                try{
                    while((line = br.readLine()) != null){
                        String buf[] = line.trim().split(" +");//空白が一回以上で区切る
                        K = Integer.parseInt(buf[0]);
                        X = Integer.parseInt(buf[1]);
                        int sum = 500*K;
                        if(sum >= X) System.out.println("Yes");
                        else System.out.println("No");
                    }
                }catch(Exception e){
                    e.getStackTrace();
                }
        }
}