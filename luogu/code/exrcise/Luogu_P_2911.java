
import java.util.Scanner;

public class Luogu_P_2911 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int a1, a2, a3;
        a1 = in.nextInt();
        a2 = in.nextInt();
        a3 = in.nextInt();

        int n = a1 + a2 + a3 + 1;
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            cnt[i] = 0;
        }

        int mx = 0;

        for (int i = 1; i <= a1; i++) {
            for (int j = 1; j <= a2; j++) {
                for (int k = 1; k <= a3; k++) {
                    mx = Math.max(++cnt[i + j + k], mx);
                }
            }
        }

        int ans = 1005;
        for (int i = 3; i < n; i++) {
            if (cnt[i] == mx) {
                ans = Math.min(ans, i);
            }
        }

        System.out.println(ans);

        in.close();
    }
}
