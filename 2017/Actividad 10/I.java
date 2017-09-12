
import java.util.Scanner;
import java.util.Arrays;


public class I {
    
    static class nodo implements Comparable<nodo>{
        int a,b,p;

        public nodo(int a, int b, int p) {
            this.a = a;
            this.b = b;
            this.p = p;
        }

        @Override
        public int compareTo(nodo o) {
                return o.p-this.p;
        } 
    }
    static int padre[];
    static void makeSet(int n){
        padre = new int[n+5];
        for (int i = 0; i < n; i++) {
            padre[i]=i;
        }
    }
    
    static int find(int x){
        return (x==padre[x])?x : (padre[x]=find(padre[x]));
    }
    
    static void union(int x, int y){
        padre[find(x)]=find(y);
    }
    
    static boolean sameComp(int x, int y){
        if(find(x)==find(y)){
            return true;
        }
        return false;
    }
    
    public static void main(String[] args) {
        Scanner leer=new Scanner(System.in);
        int casos=leer.nextInt();
        int c=1;
        while(casos-->0){
            int n=leer.nextInt();
            int m=leer.nextInt();
            nodo ar[]=new nodo[m];
            for(int i=0; i<m; i++){
                ar[i]=new nodo(leer.nextInt(), leer.nextInt(), leer.nextInt());
            }
            Arrays.sort(ar);
            makeSet(n);
            int peso=0;
            for(int i=0; i<m; i++){
                nodo x=ar[i];
                if(!sameComp(x.a,x.b)){
                    union(x.a,x.b);
                    peso=x.p;
                    //System.out.println(peso);
                }
            }
            System.out.println("Case #"+c+": "+peso);
            c++;
        }
    }
}
