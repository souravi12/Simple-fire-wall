SIMPLE JAVA FIREWALL

Introduction
The Simple Java Firewall is a basic IP-based firewall application created in Java. It listens on a specified port (default: 8080) and controls access by allowing or blocking connections based on a predefined list of IP addresses. This project demonstrates how to implement a basic firewall using Java sockets, providing a foundation for learning network security concepts in Java.

Features
- IP Filtering: Accepts or blocks incoming connections based on configured IP addresses.
- Port Listening: Listens on a specified port for incoming TCP connections.
- Connection Logging: Logs connection attempts, indicating whether they are allowed or blocked.

Installation
1. Prerequisites:
   - Java Development Kit (JDK) installed ([Download JDK](https://www.oracle.com/java/technologies/javase-downloads.html)).

2. Download the Project:
   - Clone this repository or download the SimpleFirewall.java file.

3. Compile the Code:
   - Open a terminal in the folder containing SimpleFirewall.java.
   - Run:
     bash
     javac SimpleFirewall.java

4. Run the Firewall:
   - Execute the following command to start the firewall:
     bash
     java SimpleFirewall
     
   - The firewall will start and listen on port 8080 by default.

Usage
1. Configure IP Lists:
   - Open SimpleFirewall.java.
   - Add IP addresses to the allowedIPs and blockedIPs sets to control which IPs can connect.
     java
     allowedIPs.add("127.0.0.1");  // Localhost
     blockedIPs.add("192.168.1.10");  // Example blocked IP
     
   - Save and recompile the program after making changes to IP configurations.

2. Test Connections:
   - Connect to the firewall from a browser or using telnet:
     bash
     telnet localhost 8080
     
   - Logs in the terminal indicate whether the connection was accepted or blocked.

3. Monitor Connections in Wireshark:
   - Filter traffic by port 8080 in Wireshark to observe packet behavior:
     text
     tcp.port == 8080
     
   - Alternatively, use broader filters if required.

Contributing
Contributions are welcome! Follow these steps to contribute:

1. Fork this repository.
2. Create a new branch (git checkout -b feature/YourFeature).
3. Commit your changes (git commit -m 'Add your feature').
4. Push to the branch (git push origin feature/YourFeature).
5. Open a pull request.

Feel free to report issues or suggest new features by opening an issue in the Issues tab.

