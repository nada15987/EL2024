import socket
import threading

# Function to handle client connections
def handle_client(client_socket, client_address):
    print(f"Connection from {client_address} has been established!")

    #loop to receive data and send it back
    while True:
        try:
            message = client_socket.recv(1024).decode('utf-8')
            if not message:
                break
            print(f"Received from {client_address}: {message}")
            response = f"Echo: {message}"
            client_socket.send(response.encode('utf-8'))
        except ConnectionResetError:
            break
    print(f"Connection from {client_address} has been closed!")
    client_socket.close()

# Main function to set up the server
def main():
    #create a socket
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Bind the socket to a specific IP address and port
    server.bind(("0.0.0.0", 9999)) 
    #Using '0.0.0.0' tells the server to bind to all available network interfaces on the machine
    
      # Listen for incoming connections (up to 5 clients)
    server.listen(5)
    print("Server started and listening on port 9999...")

    #main server loop
    while True:
        #accept a new connection
        client_socket, client_address = server.accept()

        #handle the client(response)
        client_handler = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_handler.start()

if __name__ == "__main__":
    main()
