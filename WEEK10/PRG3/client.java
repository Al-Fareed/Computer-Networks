import java.io.*;
import java.net.*;

public class client {
    public static void main(String[] args) throws IOException{
        byte buf[] = new byte[1024];
        int cport = 789,sport = 790;
           DatagramSocket clientsocket = new DatagramSocket(cport);

         DatagramPacket dp = new DatagramPacket(buf, sport);
         BufferedReader dis = new BufferedReader(new InputStreamReader(System.in));
         InetAddress ia = InetAddress.getLocalHost();
         String s;
         System.out.print("Client:");
         s = new String(dis.readLine());
         buf = s.getBytes();
            clientsocket.send(new DatagramPacket(buf,s.length(),ia,sport));
           clientsocket.receive(dp);
           String str = new String(dp.getData(),0,dp.getLength());
           System.out.println("SErver:"+str);
    }
    
}
