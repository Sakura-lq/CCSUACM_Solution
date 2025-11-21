import java.util.Scanner;

public class A_Beautiful_Year {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int y = in.nextInt();

        while(true)
        {
            y++;
            int k = y;
            int cnt[] = new int[10];
            boolean flag = true;

            while (k > 0) {
                if (cnt[k % 10] != 0) {
                    flag = false;
                    break;
                }
                cnt[k % 10]++;
                k /= 10;
            }

            if (flag) {
                System.out.println(y);
                in.close();
                return;
            }
        }
    }
}