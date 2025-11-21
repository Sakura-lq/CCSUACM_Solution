import java.util.Scanner;

public class B_Queue_at_the_School {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int t = in.nextInt();
        String s = in.next();

        in.close();

        char[] queue = s.toCharArray();

        while (t-- > 0) {
            for (int i = 0; i < n - 1; i++) {
                if (queue[i] == 'B' && queue[i + 1] == 'G') {
                    queue[i] = 'G';
                    queue[i + 1] = 'B';
                    i++;
                }
            }
        }

        System.out.println(new String(queue));
    }
}