import java.io.BufferedReader;
import java.io.InputStreamReader;
public class ReadLineSample {

  ReadLineSample(String line){
    int x[] = getpos(line);
    for(int i = 0; i < x.length; i++){
      System.out.print(x[i]+" ");
    }
    
  }

  public static void main(String[] args) {
    try {
      BufferedReader stdReader =
        new BufferedReader(new InputStreamReader(System.in));
      System.out.print("INPUT : ");
      String line;
      while ((line = stdReader.readLine()) != null) { // ユーザの一行入力を待つ
        System.out.println(line);
        new ReadLineSample(line);
      }
      stdReader.close();
    } catch (Exception e) {
      e.getStackTrace();
      System.exit(-1); // プログラムを終了
    }
  }

  int[] getpos(String posline) {
		String []s=posline.trim().split(" +");//空白が一回以上で区切る
		int []pdat = new int[s.length]; // assume data
		for (int i=0;i<s.length;++i) {
			pdat[i]=s2int(s[i], pdat[i]);
		}
		return pdat;
	}
	int s2int(String s, int as) {
		int r;
		try {
			r=Integer.parseInt(s);
		} catch (NumberFormatException e) {
			r=as;
		}
		return r;
	}
}