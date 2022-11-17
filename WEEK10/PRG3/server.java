import java.io.*;
import java.net.*;
public class server {
    public static void main(String[] args) throws IOException{
        byte buf[] = new byte[1024];
        int cport = 789,sport = 790;
           DatagramSocket serversocket = new DatagramSocket(sport);

         DatagramPacket dp = new DatagramPacket(buf, sport);
         BufferedReader dis = new BufferedReader(new InputStreamReader(System.in));
         InetAddress ia = InetAddress.getLocalHost();
         String s;
         serversocket.receive(dp);
           String str = new String(dp.getData(),0,dp.getLength());
           System.out.println("Client:"+str);
           
         System.out.print("Server:");
         s = new String(dis.readLine());
         buf = s.getBytes();
         serversocket.send(new DatagramPacket(buf,s.length(),ia,cport));
         
    }
}
