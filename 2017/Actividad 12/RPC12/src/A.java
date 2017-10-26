
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;

public class A {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        while ((line = br.readLine()) != null) {
            int N = Integer.parseInt(line.trim());
            System.out.println(calculateFormula(N));
        }
    }

    private static String calculateFormula(int N) {
        BigInteger n = new BigInteger(String.valueOf(N));
        BigInteger n2 = n.multiply(n);
        BigInteger two = new BigInteger("2");
        BigInteger three = new BigInteger("3");
        BigInteger num = three.multiply(n2.add(n));
        BigInteger den = two.multiply(n2).add(three.multiply(n)).add(BigInteger.ONE);
        if (num.remainder(den).compareTo(BigInteger.ZERO) != 0) {
            BigInteger gcd = num.gcd(den);
            return String.format("%s/%s", num.divide(gcd), den.divide(gcd));
        } else {
            return num.divide(den).toString();
        }
    }
}
