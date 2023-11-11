import java.io.*;
import java.net.*;

public class Udp_server {

  public static void main(String[] args) throws IOException {
    DatagramSocket dsock = new DatagramSocket(8000);
    byte[] receive = new byte[65535];
    DatagramPacket DpReceive = null;
    System.out.println("Server started waiting for client to type");
    while (true) {
      DpReceive = new DatagramPacket(receive, receive.length);
      dsock.receive(DpReceive);
      System.out.println("Client typed : " + data(receive));
      if (data(receive).toString().equals("close")) {
        System.out.println("Connection Closed ");
        break;
      }
      receive = new byte[65535];
    }
  }

  public static StringBuilder data(byte[] a) {
    if (a == null) return null;
    StringBuilder ret = new StringBuilder();
    int i = 0;
    while (a[i] != 0) {
      ret.append((char) a[i]);
      i++;
    }
    return ret;
  }
}
