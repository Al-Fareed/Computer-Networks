import java.io.*;
import java.net.*;
public class server {
    public static void main(String[] args)throws IOException {
        ServerSocket ss = new ServerSocket(1234);
        Socket sk = ss.accept();
        BufferedReader cin = new BufferedReader(new InputStreamReader(sk.getInputStream()));
        PrintStream cout = new PrintStream(sk.getOutputStream());
        BufferedReader sin = new BufferedReader(new InputStreamReader(System.in));
        String s;
        Boolean flag = true;
        while(flag)
        {
            s = cin.readLine();
            if(s.equalsIgnoreCase("bye"))
            {
                System.out.println("Terminating chat...");
                flag = false;
            }
            else
            {
                System.out.println("Client:"+s);
                System.out.print("You : ");
                s = sin.readLine();
                cout.println(s);
            }
        }
    }
}
