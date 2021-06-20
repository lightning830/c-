import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main{
    Scanner scan = new Scanner(System.in);
    int card[] = new int[5];
    int A = 1; int B = 2; int C = 3;//人に番号を振る
    int Acard,Bcard,Ccard;
    int Athink[] = new int[5];
    int Bthink[] = new int[5];
    int Cthink[] = new int[5];
    boolean Asay = false;
    boolean Bsay = false;
    boolean Csay = false;//?といったか


    Main(){

        Acard = scan.nextInt();
        Bcard = scan.nextInt();
        Ccard = scan.nextInt();
        //System.out.println(Acard);
        think();
    }

    public void think(){
        for(int i=0; i<5; i++){
            if(i == Bcard-1 || i == Ccard-1){
                Athink[i] = 1;
            }else{Athink[i] = 0;}
            if(i == Acard-1 || i == Ccard-1){
                Bthink[i] = 1;
            }else{Bthink[i] = 0;}
            if(i == Acard-1 || i == Bcard-1){
                Cthink[i] = 1;
            }else{Cthink[i] = 0;}//0はそこに入る可能性があること
        }
        /*
        for(int i=0; i<5; i++){
            System.out.print(Bthink[i]);
        }*/
        while(true){
            //a
            if(Bsay){
                if(Ccard == 1 && Athink[1] != 1)Athink[1] = 2;
                if(Ccard == 2 && Athink[0] != 1)Athink[0] = 2;
                if(Ccard == 4 && Athink[4] != 1)Athink[4] = 2;
                if(Ccard == 5 && Athink[3] != 1)Athink[3] = 2;
            }
            if(Csay){
                if(Bcard == 1 && Athink[1] != 1)Athink[1] = 2;
                if(Bcard == 2 && Athink[0] != 1)Athink[0] = 2;
                if(Bcard == 4 && Athink[4] != 1)Athink[4] = 2;
                if(Bcard == 5 && Athink[3] != 1)Athink[3] = 2;
            }
            if(check(Athink, A)) break;
            //b
            if(Asay){
                if(Ccard == 1 && Bthink[1] != 1)Bthink[1] = 2;
                if(Ccard == 2 && Bthink[0] != 1)Bthink[0] = 2;
                if(Ccard == 4 && Bthink[4] != 1)Bthink[4] = 2;
                if(Ccard == 5 && Bthink[3] != 1)Bthink[3] = 2;
            }
            if(Csay){
                if(Acard == 1 && Bthink[1] != 1)Bthink[1] = 2;
                if(Acard == 2 && Bthink[0] != 1)Bthink[0] = 2;
                if(Acard == 4 && Bthink[4] != 1)Bthink[4] = 2;
                if(Acard == 5 && Bthink[3] != 1)Bthink[3] = 2;
            }
            if(check(Bthink, B)) break;
            //c
            if(Bsay){
                if(Acard == 1 && Cthink[1] != 1)Cthink[1] = 2;
                if(Acard == 2 && Cthink[0] != 1)Cthink[0] = 2;
                if(Acard == 4 && Cthink[4] != 1)Cthink[4] = 2;
                if(Acard == 5 && Cthink[3] != 1)Cthink[3] = 2;
            }
            if(Asay){
                if(Bcard == 1 && Cthink[1] != 1)Cthink[1] = 2;
                if(Bcard == 2 && Cthink[0] != 1)Cthink[0] = 2;
                if(Bcard == 4 && Cthink[4] != 1)Cthink[4] = 2;
                if(Bcard == 5 && Cthink[3] != 1)Cthink[3] = 2;
            }

            if(check(Cthink, C)) break;

        }

    }

    public boolean check(int think[], int human){
        ArrayList<Integer> thinkcp = new ArrayList<>();
        for(int i=0; i<5; i++){
            thinkcp.add(think[i]);
        }
        thinkcp.remove(Integer.valueOf(2));

        if(thinkcp.get(0) == 1 && thinkcp.get(1) == 1){
            if(human == A)System.out.print("A");
            else if(human == B)System.out.print("B");
            else if(human == C)System.out.print("C");
            System.out.print("->MAX ");
            return true;
        }else if(thinkcp.get(thinkcp.size()-2) == 1 && thinkcp.get(thinkcp.size()-1) == 1){
            if(human == A)System.out.print("A");
            else if(human == B)System.out.print("B");
            else if(human == C)System.out.print("C");
            System.out.print("->MIN ");
            return true;
        }else if(thinkcp.get(0) == 1 && thinkcp.get(thinkcp.size()-1) == 1){
            if(human == A)System.out.print("A");
            else if(human == B)System.out.print("B");
            else if(human == C)System.out.print("C");
            System.out.print("->MID ");
            return true;
        }else{
            if(human == A){System.out.print("A");Asay = true;}
            else if(human == B){System.out.print("B");Bsay = true;}
            else if(human == C){System.out.print("C");Csay = true;}
            System.out.print("->? ");
            return false;
        }
    }

    public static void main(String[] args){
        new Main();
    }
}