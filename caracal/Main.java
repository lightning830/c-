import java.util.Scanner;
import java.util.ArrayList;

public class Main{
    Scanner scan = new Scanner(System.in);
    long H;

    Main(){
        H = scan.nextLong();
        minimize(H);
    }

    public void minimize(long H){
        ArrayList<Long> Hs = new ArrayList<>();
        Hs.add(H);
        long num = 0;
        while(true){
            boolean clear = true;
            for(int i = 0; i < Hs.size(); i++){
                if(Hs.get(i) == 0)continue;
                if(Hs.get(i) == 1){
                    Hs.set(i, (long)0);
                }else{
                    clear = false;
                    Hs.add(Hs.get(i)/2);
                    Hs.set(i, Hs.get(i)/2);
                }
                num++;
                /*
                for(int j = 0; j < Hs.size(); j++){
                    System.out.print(Hs.get(j)+" ");
                }
                
                System.out.println();*/
            }
            if(clear)break;
        }
        System.out.println(num);
    }



    public static void main(String[] args){
        new Main();
    }
}