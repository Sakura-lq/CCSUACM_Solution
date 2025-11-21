import java.util.Scanner;

public class A_Vanya_and_Fence {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int h = in.nextInt();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int x = in.nextInt();
            if (x > h) {
                ans += 2;
            } else {
                ans++;
            }
        }
        
        System.out.println(ans);
        in.close();
    }
}