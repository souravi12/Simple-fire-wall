
Set ([Download JDK](https://www.oracle.com/java/technologies/javase-downloads.html)).
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.HashSet;
import java.util.Set;

public class SimpleFirewall {
    private static final int PORT = 8080; // Port to listen on
    private static Set<String> allowedIPs = new HashSet<>();
    private static Set<String> blockedIPs = new HashSet<>();

    public static void main(String[] args) {
        // Define allowed and blocked IPs
        allowedIPs.add("127.0.0.1"); // Allow local connections
        blockedIPs.add("192.168.1.10"); // Example of a blocked IP
   

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Firewall is active on port " + PORT);

            while (true) {
                // Accept incoming connections
                Socket socket = serverSocket.accept();
                String clientIP = socket.getInetAddress().getHostAddress();
                
                if (isAllowed(clientIP)) {
                    System.out.println("Accepted connection from " + clientIP);
                    // Proceed with further handling of the connection if necessary
                    handleClient(socket);
                } else {
                    System.out.println("Blocked connection from " + clientIP);
                    socket.close(); // Close the connection if IP is blocked
                }
            }
        } catch (IOException e) {
            System.out.println("Firewall encountered an error: " + e.getMessage());
        }
    }

    // Method to handle allowed connections
    private static void handleClient(Socket socket) {
        try {
            // Here you can handle the allowed connection (e.g., read/write data)
            socket.getOutputStream().write("Welcome to the server\n".getBytes());
            socket.close();
        } catch (IOException e) {
            System.out.println("Error handling client: " + e.getMessage());
        }
    }

    // Check if the IP is allowed
    private static boolean isAllowed(String ip) {
        if (blockedIPs.contains(ip)) {
            return false;
        }
        return allowedIPs.isEmpty() || allowedIPs.contains(ip);
    }
}