import java.util.Scanner;

public class charCount {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter frame count: ");
        int fc = sc.nextInt();
        String[] frameList = new String[fc];

        for (int i = 0; i < fc; i++) {
            System.out.print("Enter frame: ");
            frameList[i] = sc.next();    // ⭐⭐
        }

        String stuffedStr = "";

        for (String i : frameList) {
            stuffedStr += Integer.toString(i.length() + 1) + i;
        }

        System.out.println("Stuffed Message: " + stuffedStr);
    }
}
