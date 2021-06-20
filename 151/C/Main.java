import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main{
    Scanner scan = new Scanner(System.in);
    int N,M;
    int p[];
    String s[];
    boolean AC[];
    int WA[];
    int penalty[];

    Main(){
        N = scan.nextInt();
        M = scan.nextInt();
        p = new int[M];
        s = new String[M];
        AC = new boolean[N];
        WA = new int[N];
        penalty = new int[N];

        int acs=0;
        for(int i=0; i<N; i++){
            AC[i] = false;
            WA[i] = 0;
            penalty[i] = 0;
        }

        for(int i=0; i<M; i++){
            p[i] = scan.nextInt();
            s[i] = scan.next();
        }
        for(int i=0; i<M; i++){
            if(s[i].equals("WA")){
                WA[p[i]-1] += 1;
            }else{
                if(!AC[p[i]-1]){
                    AC[p[i]-1] = true;
                    acs += 1;
                    penalty[p[i]-1] += WA[p[i]-1];
                }
            }


        }
        
        int penaltys = 0;
        for(int i=0; i<N; i++){
            penaltys += penalty[i];
            //System.out.println(penalty[i]);
        }

        System.out.println(acs+" "+penaltys);


    }

    public static void main(String[] args){
        new Main();
    }
}