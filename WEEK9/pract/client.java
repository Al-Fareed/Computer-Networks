import java.io.*;
import java.net.*;

public class client
{
    public static void main(String[] args)throws Exception{
        Socket sk = new Socket("127.0.0.1",1234);
        BufferedReader sin = new BufferedReader(new InputStreamReader(sk.getInputStream()));
        PrintStream sout = new PrintStream(sk.getOutputStream());
        BufferedReader cin  = new BufferedReader(new InputStreamReader(System.in));
        String s;
        Boolean flag = true;
        while(flag)
        {
            System.out.print("Me:");
            s = cin.readLine();
            if(s.equalsIgnoreCase("bye"))
            {
                System.out.println("Terminating...");
                flag = false;
            }
            sout.println(s);
            s = sin.readLine();
            System.out.println("Server:"+s);
        }
   
    }
    
}