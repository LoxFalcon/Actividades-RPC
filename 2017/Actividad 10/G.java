
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author luis0
 */
public class G {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int casos = Integer.parseInt(br.readLine().trim());
        //int S[] = new int[105];
        while (casos-- > 0) {
            String line[] = br.readLine().trim().split(" ");
            int disc = 0, maxi = -1, index = -1;
            
            for (int i = 0; i < line.length; i++) {
                int tmp = Integer.parseInt(line[i]);
                if(tmp>maxi){
                    disc = 0;
                    maxi = tmp;
                    index = i;
                }else if(tmp==maxi){
                    if(index != -1){
                        disc+= (i-index+1);
                        index = -1;
                    }else{
                        index = i;
                    }
                }
            }
            if(index != -1){
                disc+=(line.length-index);
            }
            System.out.println(disc);
        }
    }
}
