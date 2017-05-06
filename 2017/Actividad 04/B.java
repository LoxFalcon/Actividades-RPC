
import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner leer=new Scanner(System.in);
        int n=leer.nextInt();
        int b=leer.nextInt();
        while(n!=0 && b!=0){
            int suma=0;
            for (int i = 0; i < n; i++) {
                suma+=leer.nextInt();
            }
            System.out.println(b/suma);
            n=leer.nextInt();
            b=leer.nextInt();
        }
    }
}
