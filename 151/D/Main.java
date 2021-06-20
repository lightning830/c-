import java.util.Scanner;
import java.util.LinkedList;
import java.util.List;
import java.awt.Point;

public class Main{
    Scanner scan = new Scanner(System.in);
    List<Node> nodes = new LinkedList<>();
    int H, W;
    int[][] S;//map H*W(横がW)
    Point start = new Point();//x = W, y = H(横がx)
    Point end = new Point();
    Node nowNode = new Node(0, 0);
    int maxstep = 0;

    Main(){
        H = scan.nextInt();
        W = scan.nextInt();
        S = new int[H][W];
        for(int i=0; i<H; i++){
            char str[] = scan.next().toCharArray();
            //System.out.println(str);
            for(int j=0; j<W; j++){
                if(str[j] == '.'){
                    S[i][j] = 0;//can move
                }else{
                    S[i][j] = 1;
                }
            }
        }

        // end.x = 1; end.y = 1;
        // start.x = 2; start.y = 0;
        // nowNode.x = start.x; nowNode.y = start.y;
        // Asearch(start, end);


        for(int i=0; i<H; i++){//start
            for(int j=0; j<W; j++){
                if(S[i][j] == 0){//canMove
                    start.x = j; start.y = i;
                    for(int k=0; k<H; k++){//end
                        for(int l=0; l<W; l++){
                            if(S[k][l] == 0){//canMove
                                if(i != k || j != l){
                                    end.x = l; end.y = k;
                                    nowNode = new Node(0, 0);
                                    nodes.clear();
                                    nowNode.x = start.x; nowNode.y = start.y;
                                    // System.out.println("start="+start+"end="+end);
                                    Asearch(start, end);

                                }
                            }
                        }
                    }
                }
            }
        }

        System.out.println("maxstep="+maxstep);

        
        // for(int i=0; i<H; i++){
        //     for(int j=0; j<W; j++){
        //         System.out.print(S[i][j]);
        //     }
        //     System.out.println();
        // }
    }

    public void Asearch(Point start, Point end){
        nowNode = new Node(start.x, start.y);
        nowNode.h = heuristic(start);
        nowNode.open();
        nodes.add(nowNode);//add to openList

        loop: while(true){
            opener(nowNode);//step1
            closer(nowNode);//step2
            
            if(nodes == null || nodes.size() == 0 || !allclose()){
                System.out.println("no way");
                break;
            }
            int min = 2 * (H + W);
            Node temp = new Node(0,0);
            for(Node n: nodes){
                // System.out.print("min="+min+"cost="+n.cost());
                if(min >= n.cost() && n.state != 2){
                    min = n.cost();
                    temp = n;
                }
            }
            nowNode = temp;
            if(nowNode.x == end.x && nowNode.y == end.y){
                System.out.println("step"+nowNode.cost()+"GOAL");
                if(maxstep < nowNode.cost()){
                    maxstep = nowNode.cost();
                }
                break loop;
            }
            // for(Node n: nodes){
            //     // System.out.print("min="+min+"cost="+n.cost());
            //     if(min >= n.cost() && n.state != 2){
            //         System.out.println("dd");
            //         nowNode = n;
            //         if(n.x == end.x && n.y == end.y){
            //             System.out.println("step"+nowNode.cost()+"GOAL");
            //             if(maxstep < nowNode.cost()){
            //                 maxstep = nowNode.cost();
            //             }
            //             break loop;
            //         }
            //     } 
            // }

            //printnow();
            // printNodes();
        }

    }
    public boolean allclose(){
        boolean check = false;
        for(Node n: nodes){
            if(n.state != 2) check = true;
        }
        return check;
    }

    public void printnow(){
        System.out.print("{"+nowNode.x+","+nowNode.y+"}");
    }

    public void printNodes(){
        for(Node n: nodes){
            System.out.print("("+n.x+","+n.y+")");
            System.out.print(n.state);
        }
        System.out.println();
    }


    public void closer(Node now){
        // for(int i=0; i<nodes.size(); i++){
        //     if(nodes.get(i).x == now.x && nodes.get(i).y == now.y){
        //         nodes.remove(o)
        //     }
        // }
        for(Node n: nodes){
            if(n.x == now.x && n.y == now.y){
                n.close();
            }
        }
    }
    public boolean stillClose(Point p){
        boolean check = false;
        for(Node n: nodes){
            if(n.x == p.x && n.y == p.y && n.state == 2){
                // System.out.print(check);
                check = true;
            }
        }
        return check;
    }

    public void opener(Node now){
        boolean check = false; // can open
        if(now.x+1 < W && S[now.y][now.x+1] == 0 && !stillClose(new Point(now.x+1,now.y))){
            check = true;
            // System.out.print("["+now.x+","+now.y+"]");
            Node temp = new Node(now.x+1, now.y);
            temp.open();
            temp.g = now.g+1;
            temp.h = heuristic(new Point(now.x+1, now.y));
            // System.out.print("["+temp.x+","+temp.y+"]");

            nodes.add(temp);
            // System.out.print("addx+");
        }
        if(now.y-1 >= 0 && S[now.y-1][now.x] == 0 && !stillClose(new Point(now.x,now.y-1))){
            check = true;

            // System.out.print("["+now.x+","+now.y+"]");
            Node temp = new Node(now.x, now.y-1);
            temp.open();
            temp.g = now.g+1;
            temp.h = heuristic(new Point(now.x, now.y-1));
            // System.out.print("["+temp.x+","+temp.y+"]");

            nodes.add(temp);
            // System.out.print("addy-");

        }
        if(now.x-1 >= 0 && S[now.y][now.x-1] == 0 && !stillClose(new Point(now.x-1,now.y))){
            check = true;

            // System.out.print("["+now.x+","+now.y+"]");
            Node temp = new Node(now.x-1, now.y);
            temp.open();
            temp.g = now.g+1;
            temp.h = heuristic(new Point(now.x-1, now.y));
            // System.out.print("["+temp.x+","+temp.y+"]");

            nodes.add(temp);
            // System.out.print("addx-");

        }
        if(now.y+1 < H && S[now.y+1][now.x] == 0 && !stillClose(new Point(now.x,now.y+1))){
            check = true;

            // System.out.print("["+now.x+","+now.y+"]");
            Node temp = new Node(now.x, now.y+1);
            temp.open();
            temp.g = now.g+1;
            temp.h = heuristic(new Point(now.x, now.y+1));
            // System.out.print("["+temp.x+","+temp.y+"]");
            nodes.add(temp);          
            // System.out.print("addy+");

        }
        if(!check) now.close();

    }

    public int heuristic(Point now){
        int dx = end.x - now.x;
        int dy = end.y - now.y;
        return Math.abs(dx)+Math.abs(dy);
    }

    

    public static void main(String[] args){
        new Main();
    }
}

class Node{
    static final int OPEN = 1;
    static final int CLOSE = 2;
    static final int NONE = 0;
    int x, y;
    int g = 0;
    int h = 0;
    int state = NONE;

    Node(int x, int y){
        this.x = x; this.y = y;
    }

    public int cost(){
        return this.g+this.h;
    }

    public void open(){
        this.state = OPEN;
    }
    public void close(){
        this.state = CLOSE;
    }

}