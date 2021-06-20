import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int num = scan.nextInt();
        int abcnum = 0;
        char[] s = scan.next().toCharArray();
        for(int i=0; i<num-2; i++){
            if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){
                abcnum++;
            }
        }
        scan.close();
        System.out.println(abcnum);
    }
}