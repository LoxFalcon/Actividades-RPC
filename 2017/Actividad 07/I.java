import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class waifuntil {
    static int t,s,f,v;
    static int INF=1000000000;
    static int[][] res;
    static ArrayList<Integer> p=new ArrayList<>();
    static void augment(int v, int minEdge){
        if(v==s){f=minEdge; return;}
        else if(p.get(v)!= -1){
            augment(p.get(v),res[p.get(v)][v]);
            res[p.get(v)][v]-=f;
            res[v][p.get(v)]+=f;
        }
    }
    public static void main(String[] args) {
        Scanner leer=new Scanner(System.in);
        int a,b,c;
        a=leer.nextInt();
        b=leer.nextInt();
        c=leer.nextInt();
        int total=a+b+c;
        s=0;t=total+1;
        v=total+2;
        res=new int[total+2][total+2];
        for(int i=1;i<=a;i++){
            res[s][i]=1;
        }
        int nod;
        for(int i=1; i<=a;i++){
            int x=leer.nextInt();
            for(int j=0; j<x;j++){
                nod=leer.nextInt();
                res[i][nod+a]=1;
            }
        }
        boolean jug[]=new boolean [b];
        int cat[]=new int[c];
        for(int i=0; i<c;i++){
            int x=leer.nextInt();
            for(int j=0;j<x;j++){
                nod=leer.nextInt();
                jug[nod-1]=true;
                res[a+nod][a+b+1+i]=1;
            }
            cat[i]=leer.nextInt();
        }
        //System.out.println("entra");
        for(int i=0; i<c;i++){
            res[a+b+i+1][t]=cat[i];
        }
        for(int i=0;i<b;i++){
            if(!jug[i]){
                res[a+1+i][t]=1;
            }
        }
       /* for(int i=0; i<v;i++){
            for(int j=0; j<v;j++){
                System.out.print(res[i][j]+" ");
            }
            System.out.println("");
        }*/
        int mf=0;
        while(true){
          
            f=0;
            Queue<Integer> q=new LinkedList<Integer>();
            ArrayList<Integer> dist=new ArrayList<>();
            dist.addAll(Collections.nCopies(v,INF));
            q.offer(s);
            dist.set(s,0);
            p.clear();
            p.addAll(Collections.nCopies(v,-1));
            while(!q.isEmpty()){
                int u=q.poll();
                if(u==t){
                    break;
                }
                for(int i=0; i<v; i++){
                    if(res[u][i]>0 && dist.get(i)==INF){
                        dist.set(i,dist.get(u)+1);
                        q.offer(i);
                        p.set(i,u);
                    }
                }
            }
            augment(t,INF);
            if(f==0) break;
            mf+=f;
        }
        System.out.println(mf);
    }
}
