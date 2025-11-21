import java.util.Scanner;

public class A_Translation {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();
        String t = in.nextLine();
        
        String rever = new StringBuilder(s).reverse().toString();
        
        System.out.println((rever.equals(t) ? "YES" : "NO"));
        
        in.close();
    }
}
