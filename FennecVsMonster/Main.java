import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    Scanner scan = new Scanner(System.in);
    int N;
    ArrayList<Integer> H = new ArrayList<>();
    int K;
    int min;

    Main(){
        N = scan.nextInt();
        K = scan.nextInt();

        for(int i = 0; i < N; i++){
            H.add(scan.nextInt());
        }

        System.out.println(minmize(N, K, H));
        /*
        for(int i = 0; i < H.size(); i++){
            System.out.println(H.get(i));
        }*/
    }

    public long minmize(int N, int K, ArrayList<Integer> H){
        long sumhp = 0;
        Collections.sort(H);
        for(int i = 0; i < H.size() - K; i++){
            sumhp += H.get(i);
        }
        return sumhp;

    }


    public static void main(String[] args){
        new Main();
    }
}