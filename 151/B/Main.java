import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    Scanner scan = new Scanner(System.in);
    int N,K,M;
    int[] A;
    int sum = 0;
    int must;

    Main(){
        N = scan.nextInt();
        K = scan.nextInt();
        M = scan.nextInt();
        A = new int[N-1];
        for(int i=0; i<N-1; i++){
            A[i] = scan.nextInt();
            sum += A[i];
        }
        must = M*N - sum;
        if(must < 0) must = 0;
        if(must > K) System.out.println(-1);
        else{System.out.println(must);}
        

    }

    public static void main(String[] args){
        new Main();
    }
}