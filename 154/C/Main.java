import java.util.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;

public class Main {

    
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        //ArrayList<Integer> list;
        List<Integer> list = new ArrayList<>(200000);
        
        int number = sc.nextInt();
        for(int i = 0; i < number ; i++){
            list.add(sc.nextInt());
        }

        Collections.sort(list);
        int count = 0;
        // for(int i = 0; i < list.size(); i++){
        //     System.out.print(list.get(i)+" ");
        // }
        for(int i = 0; i < number - 1 ; i++){
            if(list.get(i).equals(list.get(i+1))){
                count++;
            }else{}
        }


        if(count == 0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
        


    
	}
}