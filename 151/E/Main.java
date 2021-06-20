import java.io.*;
import java.net.InterfaceAddress;

public class Main{
    static int N, K;
    static int[] x;

    Main(){

        
    }


    public static void main(String[] args){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        try {
            String s = in.readLine();
            String buf[] = s.trim().split(" +");
            N = Integer.parseInt(buf[0]);
            K = Integer.parseInt(buf[1]);

            String s1 = in.readLine();
            String buf1[] = s1.trim().split(" +");
            x = new int[buf1.length];
            for(int i=0; i<buf1.length; i++){
                x[i] = Integer.parseInt(buf1[i]);
            }
            in.close();
            new Main();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}