import java.util.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Collections;

public class atcorder155_2 {
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        // 整数の入力
        List<Long> list = new ArrayList<>(200000);
        List<Long> list2 = new ArrayList<>();
        int num = sc.nextInt();
        int count = 0;
        int k = sc.nextInt();

        for(int i = 0; i < num; i++){
            list.add(sc.nextLong());
        }

        for(int i = 0; i < num; i++){
            for(int j = 0; j < num; j++){
            if(j>count){
                list2.add(list.get(j) * list.get(count));
            }
        }
            count++;
        }

        Collections.sort(list2);
        //System.out.println(list2);
        System.out.println(list2.get(k-1));
        

    
	}
}