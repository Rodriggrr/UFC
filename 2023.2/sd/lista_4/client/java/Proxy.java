package client.java;
import java.net.*;
import java.io.*;

public class Proxy {
    private Socket socket;
    private String host;
    private int port;
    
    private void connect() {
        try {
            this.socket = new Socket(this.host, this.port);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
    
    Proxy() {
        this.host = "127.0.0.1";
        this.port = 49110;
        connect();
    }

    Proxy(String host, int port) {
        this.host = host;
        this.port = port;
        connect();
    }

    double add(double a, double b){
        String str = "ADD," + a + ";" + b;
        send(str);
        return number(recv());
    }

    double sub(double a, double b){
        String str = "SUB," + a + ";" + b;
        send(str);
        return number(recv());
    }

    double mul(double a, double b){
        String str = "MUL," + a + ";" + b;
        send(str);
        return number(recv());
    }

    double div(double a, double b){
        String str = "DIV," + a + ";" + b;
        send(str);
        return number(recv());
    }

    private void send(String str) {
        try {
            DataOutputStream out = new DataOutputStream(this.socket.getOutputStream());
            out.write(str.getBytes());
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    private String recv() {
        try {

            DataInputStream in = new DataInputStream(this.socket.getInputStream());
            byte[] bytes = new byte[1024];
            in.read(bytes);
            return new String(bytes);

        } catch (Exception e) {
            System.out.println(e);
        }
        return "-1";
    }

    private double number(String str){
        return Double.parseDouble(str);
    }
}
