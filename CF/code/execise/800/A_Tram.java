import java.util.Scanner;

public class A_Tram {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        int ans = 0;
        int m = 0;
        while(n > 0)
        {
            n--;
            int a, b;
            a = in.nextInt();
            b = in.nextInt();

            m -= a;
            m = Math.max(m, 0);
            m += b;
            ans = Math.max(m, ans);
        }

        System.out.println(ans);
    }
}