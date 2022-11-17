import java.net.*;
import java.io.*;
public class tcpclient
{
 public static void main(String args[]) throws Exception
 {
 Socket sk=new Socket("127.0.0.1",2000);
 BufferedReader sin=new BufferedReader(new InputStreamReader(sk.getInputStream()));
 PrintStream sout=new PrintStream(sk.getOutputStream());
 BufferedReader stdin=new BufferedReader(new InputStreamReader(System.in));
 String s;
 
 System.out.println("Enter a Ip Address:");
    s = stdin.readLine();


 sout.println(s);
 
 }
}