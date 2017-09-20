
import java.util.Comparator;
import java.util.ArrayList;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;

public class Main {

    private static int N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        ArrayList<Matrioshka> l1 = new ArrayList<>();
        Comparator c1 = new ComparadorN();
        Comparator c2 = new ComparadorPS();
        int caso = 1;
        String line;
        String buff[];
        while ((line = br.readLine()) != null) {
            buff = line.trim().split(" ");
            N = Integer.parseInt(buff[0]);
            if (N <= 0) {
                break;
            }
            l1.clear();
            K = Integer.parseInt(buff[1]);
            for (int i = 0; i < N; i++) {
                buff = br.readLine().trim().split(" ");
                int s = Integer.parseInt(buff[0]), p = Integer.parseInt(buff[1]);
                l1.add(new Matrioshka(p, s));
            }
            Collections.sort(l1, c1);
            long suma = 0;
            for (int i = 0; i < l1.size(); i++) {
                Matrioshka tmp = l1.get(i);
                tmp.index = i;
                if (i < K - 1) {
                    suma += (long) tmp.s;
                }
            }
            Collections.sort(l1, c2);
            double res = Double.MAX_VALUE;
            for (int i = 0; i < l1.size(); i++) {
                Matrioshka max = l1.get(i);
                if (max.index >= K - 1) {
                    res = Math.min((suma + max.s) * max.p / (double) max.s, res);
                }
            }
            System.out.printf("Case #%d: %.6f\n", caso++, res);
        }
    }

}

class Matrioshka {

    public int p, s, index;

    public Matrioshka(int p, int s) {
        this.p = p;
        this.s = s;
    }

}

class ComparadorPS implements Comparator<Matrioshka> {

    @Override
    public int compare(Matrioshka m1, Matrioshka m2) {
        long left = (long) m1.p * m2.s, right = (long) m2.p * m1.s;
        if (left < right) {
            return -1;
        } else if (left == right) {
            return 0;
        }
        return 1;
    }
}

class ComparadorN implements Comparator<Matrioshka> {

    @Override
    public int compare(Matrioshka m1, Matrioshka m2) {
        if (m1.s == m2.s) {
            return m1.p - m2.p;
        }
        return m1.s - m2.s;
    }
}
