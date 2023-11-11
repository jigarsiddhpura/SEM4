import java.io.*;
import java.net.*;
import java.util.*;

public class Udp_client {

  public static void main(String args[]) throws IOException {
    Scanner sc = new Scanner(System.in);
    DatagramSocket dsock = new DatagramSocket();
    InetAddress ip = InetAddress.getLocalHost();
    byte byt[] = null;
    System.out.println("Client started");
    while (true) {
      System.out.print("Type a message to server : ");
      String inp = sc.nextLine();
      byt = inp.getBytes();
      DatagramPacket DpSend = new DatagramPacket(byt, byt.length, ip, 8000);
      dsock.send(DpSend);
      if (inp.equals("close")) break;
    }
  }
}
