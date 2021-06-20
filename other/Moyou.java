import java.util.*;
import java.lang.Math;
public class Moyou{
    public static void main(String[] args){
        for(int i = 1; i < 18; i++){
            for(int j = 1; j < 18; j++){
                int dx = Math.abs(9-i);
                int dy = Math.abs(9-j);
                if(dx > dy){
                    System.out.print(9-dx);
                }else System.out.print(9-dy);
            }
            System.out.println();
        }
    }
}