
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n,mov; long t; char c; char charA[];
        String linea,top,mid; String buff[];
        while((linea=br.readLine())!=null){
            buff = linea.split(" ");
            n = Integer.parseInt(buff[0]);
            t = Long.parseLong(buff[1]);
            c = buff[2].charAt(0);
            top = br.readLine();
            mid = br.readLine();
            top = br.readLine();
            charA = mid.toCharArray();
                    mov = (int)(t%n);                   
                     if(c=='L') mov = -mov;        
                      for(int i=0;i<n;i++){
                              int x=i;
                              x+=mov;
                              if(x<0){
                                      x = n+x;
                              }else{
                                    x%=n;
                              }
                              
                              charA[(x<<1)+1] = mid.charAt((i<<1)+1);
                      }
                      System.out.println(top);
                      System.out.println(new String(charA));
                      System.out.println(top);
        }
        
    }
}
