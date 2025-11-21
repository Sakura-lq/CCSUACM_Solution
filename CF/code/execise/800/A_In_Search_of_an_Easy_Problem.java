import java.util.Scanner;

public class A_In_Search_of_an_Easy_Problem {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {

            int n = in.nextInt();

            for (int i = 0; i < n; i++) {
                int x = in.nextInt();

                if (x == 1) {
                    System.out.println("HARD");
                    return;
                }
            }
            
            System.out.println("EASY");
        }
    }
}