
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author luis0
 */
public class L {

    static int ar[];

    public static void main(String[] args) {
        Scanner leer = new Scanner(System.in);
        while (leer.hasNext()) {
            int n = leer.nextInt();
            int h = leer.nextInt();
            ar = new int[n];
            long x = 0, mini = Long.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                ar[i] = leer.nextInt();
                x += (long) ar[i];
                mini = Math.min(ar[i], mini);
            }
            long inf = 1, sup = x;
            long mid;
            long res = 0;
            while (inf <= sup) {
                
                mid = (inf + sup) / 2;
                //System.out.println("HOLA "+mid);
                if (succeed(mid, h)) {
                    res = mid;
                    sup = mid - 1;
                } else {
                    inf = mid + 1;
                }
            }
            System.out.println(res);
        }
    }

    static boolean succeed(long v, int h) {
        int g = 1;
        long har = v;
        for (int i = 0; i < ar.length; i++) {
            if (v < ar[i]) {
                return false;
            }
            if (har < ar[i]) {
                g++;
                har = v - ar[i];
            } else {
                har -= ar[i];
            }
            if (g > h) {
                return false;
            }
        }
        return true;
    }
}
