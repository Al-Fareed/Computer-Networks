import java.net.*;
import java.io.*;

public class tcpserver
{
 
public static void main(String args[]) throws Exception
 {
 ServerSocket ss=new ServerSocket(2000);
 Socket sk=ss.accept();
 BufferedReader cin=new BufferedReader(new InputStreamReader(sk.getInputStream()));
 PrintStream cout=new PrintStream(sk.getOutputStream());
 BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
 String a;
 System. out.println("From client : ");
 a=cin.readLine();
 System.out.println(a);
 char c[] = a.toCharArray();
int ip = 0;

 for(int i=0;i<3;i++)
 {
     ip = (ip*10);
     ip = ip + Integer.parseInt(String.valueOf(c[i]));
 }
System.out.println(ip);
if(ip==127)
System.out.println("class A");
    }
}
