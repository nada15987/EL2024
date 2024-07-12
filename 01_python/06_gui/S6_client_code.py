import socket


def main():
    #create socket
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Server's IP address and port
    server_address = ('localhost', 9999)

    #connect to the server
    client.connect(server_address)
    print(f"Connected to {server_address}")
    
    try:
        #send data (request)
        message = input("Enter message: ")
        client.send(message.encode('utf-8'))

        #receive data from the server (response)
        response = client.recv(1024).decode('utf-8')
        print(f"Received from server: {response}")
    finally:
        #close the socket connection
        print("Closing the connection.")
        client.close()

if __name__ == "__main__":
    main()
