import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.InetAddress;
import java.net.Socket;
 
public class TCPClient{ 
    private static Socket socket;

	public enum Errors{
		INVALID_IP, INVALID_PORT, INVALID_STUDNR,
		SOCKET_FAIL, CONNECTION_FAIL, SEND_FAIL, READ_FAIL
	};

    public static void main(String args[]){
		try{
			String host = "158.36.70.56";
			int port = 80;
			InetAddress address = InetAddress.getByName(host);
			socket = new Socket(address, port);
 
 			OutputStream os = socket.getOutputStream();
			OutputStreamWriter osw = new OutputStreamWriter(os);
			BufferedWriter bw = new BufferedWriter(osw);

			char stud[] = {0x01, 0, 7, 6, '2', '1', '6', '9', '8', '8'};
 
			bw.write(stud);
			bw.flush();
 
 			InputStream is = socket.getInputStream();
			InputStreamReader isr = new InputStreamReader(is);
			BufferedReader br = new BufferedReader(isr);
			String message = br.readLine();
			System.out.println(message);
			socket.close();
			System.out.println(Errors.INVALID_IP);
//			throw INVALID_IP;
		}
        catch(Exception e){
            //
        }
    }
}
