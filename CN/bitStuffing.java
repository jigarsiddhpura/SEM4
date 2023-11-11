import java.util.Scanner;

public class bitStuffing {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Message: ");
        String msg = scanner.nextLine();
        char[] msgArr = msg.toCharArray();
        String stuffedBitStr = "";
        int ctr = 0;

        for (char i : msgArr) {
            stuffedBitStr += i;
            if (i == '1') {
                ctr += 1;
            } else {
                ctr = 0;
            }
            if (ctr == 5) {
                stuffedBitStr += '0';
                ctr = 0;
            }
        }

        System.out.println("Stuffed Bit String: " + stuffedBitStr);
    }
}
