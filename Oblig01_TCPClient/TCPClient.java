import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPClient{
	private static String ip;
	private static int port;
	private static Socket sock;
	private static char studnr[] = new char[6];
	private static char buffer[] = new char[512];
	private static char stud[] = {0x01, 0, 7, 6, '2', '1', '6', '9', '8', '8'};
	
	public enum Errors{
		INVALID_IP, INVALID_PORT, INVALID_STUDNR,
		SOCKET_FAIL, CONNECTION_FAIL, SEND_FAIL, READ_FAIL
	};

    public static void main(String args[]){
		try{
			TCPClient client = new TCPClient();
			client.askUser();
			client.createSocket();
			client.sendData();
			client.readData();
			
			//char msg_id = 0x01;
			//short msg_size = 7;
			//char studnr_size = 6;
			//System.arraycopy(studnr, 0, buffer, 4, studnr.length);
		}
		catch(Exception e){
			System.out.println("ERROR: Something went wrong!");
		}
    }

	private static void askUser(){
		System.out.print("Enter the server IP address: ");
		Scanner input = new Scanner(System.in);
		String tmpIP = input.nextLine();
		if(tmpIP == "lekeplass") ip = "158.36.70.56"; else ip = tmpIP;

		System.out.print("Enter the server port: ");
		int tmpPort = input.nextInt();
		if(tmpPort <= 0 || tmpPort > 9999) System.out.println("ERROR: Invalid port!");
		else port = tmpPort;
	}

	private static void createSocket(){
		try{
			InetAddress address = InetAddress.getByName(ip);
			sock = new Socket(address, port);
		}
		catch(Exception e){
			//
		}
	}


	private static void sendData(){
		try{
			System.out.print("Enter your student number: ");
			Scanner input = new Scanner(System.in);
			String tmp = input.next();
			for(int i = 0; i < tmp.length(); i++){
				studnr[i] = tmp.charAt(i);
			}

			PrintStream ps = new PrintStream(sock.getOutputStream());
			ps.println(stud);
		}
		catch(Exception e){
			//
		}
	}

	private static void readData(){
		try{
			InputStreamReader isr = new InputStreamReader(sock.getInputStream());
			BufferedReader br = new BufferedReader(isr);
			br.read(buffer, 0, buffer.length);
			System.out.print(buffer);
		}
		catch(Exception e){
			//
		}
	}
}
