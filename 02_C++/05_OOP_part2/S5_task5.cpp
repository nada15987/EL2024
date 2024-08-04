//handle interrupt signal like (ctrl+c)

#include <iostream>
#include <csignal>  //For signal handling functionalities.
#include <unistd.h>   // For the sleep function.

// Function to handle the signal
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received.\n";
    
    // Clean up and close gracefully
    exit(signum);  
}

int main() {
    
    // Register signal handler for SIGINT (interrupt due to pressing --> Ctrl+C)
    //It is used to set up a signal handler for a particular signal
    //whenever the SIGINT signal is received (e.g., when the user presses Ctrl+C), the signalHandler function should be executed.
    signal(SIGINT, signalHandler);

    // Infinite loop to keep the program running
    while (true) {
        std::cout << "Program running. Press Ctrl+C to exit." << std::endl;
        sleep(1); // Sleep for 1 second
    }

    return 0;
}
