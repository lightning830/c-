import java.io.*;
// import java.net.InterfaceAddress;

public class Hanoi{
    static int count = 1;
    static void moveDisk(int n, int a, int b){
        if(n > 1) moveDisk(n-1, a, 6-a-b);//動かしたいDiskの上のDiskをa->6-a-bに移す。
        System.out.println((count++) + "手目:円盤" + n + "を" + a + "から" + b + "に移す");//目的のDiskを移す
        //実際に移しているわけではなくこの出力をもって、または関数の実行をもって移したとしている
        if(n > 1) moveDisk(n-1, 6-a-b, b);//動かしていた上のDiskをbに戻す。
    }

    public static void main(String[] args){
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("円盤の枚数? ");
        try {
            int n = Integer.parseInt(in.readLine());
            moveDisk(n, 1, 2);
            System.out.println("円盤"+n+"枚を柱1から柱2に移すには合計"+((1 << n)-1)+"手が必要です");
        } catch (Exception e) {
            System.out.println(e);
        }
        // moveDisk(2, 1, 3);
    }
}