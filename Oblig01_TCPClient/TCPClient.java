//import java.io.*;
//import java.net.*;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.net.InetAddress;
import java.util.Scanner;

public class TCPClient{
	private Socket sock;
	private String ip;
	private int port;
	private char bufferIn[] = new char[512];
	private char bufferOut[] = new char[10];
	
    public static void main(String args[]) throws Exception{
		try{
			TCPClient client = new TCPClient();
			client.askUser();
			client.createSocket();
			client.sendData();
			client.readData();
		}
		catch(Exception e){
			System.out.println("ERROR: Something went wrong!");
		}
    }

	private void askUser() throws Exception{
		System.out.print("Enter the server IP address: ");
		Scanner input = new Scanner(System.in);
		String tmpIP = input.nextLine();
		if(tmpIP == "lekeplass") ip = "158.36.70.56"; else ip = tmpIP;

		System.out.print("Enter the server port: ");
		int tmpPort = input.nextInt();
		if(tmpPort <= 0 || tmpPort > 99999) System.out.println("ERROR: Invalid port!");
		else port = tmpPort;
	}

	private void createSocket() throws Exception{
		InetAddress address = InetAddress.getByName(ip);
		sock = new Socket(address, port);
	}

	private void sendData() throws Exception{
		char msg_id = 0x01;
		short msg_size = 7; // kan jeg droppe short?
		char studnr_size = 6;

		bufferOut[0] = msg_id; // Message ID
		bufferOut[1] = 0; // Size of stream (Big endian)
		bufferOut[2] = (char)msg_size; // Size of stream (Big endian)
		bufferOut[3] = studnr_size; // Size of studentnr
		
		System.out.print("Enter your student number: ");
		Scanner input = new Scanner(System.in);
		String studnr = input.next();
		for(int i = 0; i < studnr.length(); i++) bufferOut[i+4] = studnr.charAt(i);
		
		PrintStream ps = new PrintStream(sock.getOutputStream());
		ps.println(bufferOut);
	}

	private void readData() throws Exception{
		InputStreamReader isr = new InputStreamReader(sock.getInputStream());
		BufferedReader br = new BufferedReader(isr);
		br.read(bufferIn, 0, bufferIn.length);
		System.out.print(bufferIn);
	}
}
