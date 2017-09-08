
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author luis
 */
public class DrunkPilots {
    public static void main(String[] args) {
        Scanner leer=new Scanner(System.in);
        int a,b,c,d;
        a=leer.nextInt();
        b=leer.nextInt();
        c=leer.nextInt();
        d=leer.nextInt();
        int cont=1;
        while(a!=0 && b!=0 && c!=0 && d!=0){
            double x,y;
            x=(b*1.0)/a;
            y=(d*1.0)/c;
            if(x<y){
                System.out.println("Case #"+cont+": You owe me a beer!");
            }else{
                System.out.println("Case #"+cont+": No beer for the captain.");
            }
            int res=lcm(a,c);
            if(a!=res){
                a=a*res;
                b=b*res;
            }
            if(c!=res){
                c=c*res;
                d=d*res;
            }
            a=a+c;
            b=b+d;
            //System.out.println("hola "+res+" "+a+" "+b);
            if(b%a==0){
                System.out.println("Avg. arrival time: "+(b/a));
            }else{
                res=gcd(a,b);
                a=a/res;
                b=b/res;
                System.out.println("Avg. arrival time: "+b+"/"+a);
            }
            a=leer.nextInt();
            b=leer.nextInt();
            c=leer.nextInt();
            d=leer.nextInt();
			cont++;
        } 
    }
    static int lcm(int a, int b) { return a * (b / gcd(a, b)); }
   static int gcd (int a, int b){
        return (b==0)? a: gcd(b,a%b);
    }
}
