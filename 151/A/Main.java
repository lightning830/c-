import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    Scanner scan = new Scanner(System.in);
    char[] C;
    char next;

    Main(){
        C = scan.nextLine().toCharArray();
        next = C[0];
        next = (char)(C[0] + 1);
        System.out.println(next);
    }

    public static void main(String[] args){
        new Main();
    }
}