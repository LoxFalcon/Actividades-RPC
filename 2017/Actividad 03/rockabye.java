
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;


public class rockabye {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T,N,K;
        String buffer[];                
        T = Integer.parseInt(br.readLine().trim());
        PriorityQueue<Med> pq = new PriorityQueue<>();
        while(T-->0){
            pq.clear();
            buffer = br.readLine().trim().split(" ");
            N = Integer.parseInt(buffer[0]);
            K = Integer.parseInt(buffer[1]);
            for (int i = 0; i < N; i++) {
                buffer = br.readLine().trim().split(" ");
                int perio = Integer.parseInt(buffer[1]);
                pq.add(new Med(i,perio,perio,buffer[0]));
            }
            for (int i = 0; i < K; i++) {
                Med x = pq.poll();
                System.out.println(x);
                x.tomar();
                pq.add(x);
            }
        }
    }
}
class Med implements Comparable<Med>{
    public int id,period,take;
    public String name;

    public Med(int id, int period, int take, String name) {
        this.id = id;
        this.period = period;
        this.take = take;
        this.name = name;
    }
    public void tomar(){
        take+=period;
    }
    @Override
    public String toString(){
        return  Integer.toString(take)+" "+name;
    }
    @Override
    public int compareTo(Med o) {
        if(take!=o.take){
            return take-o.take;
        }
        return id-o.id;
    }

    
}