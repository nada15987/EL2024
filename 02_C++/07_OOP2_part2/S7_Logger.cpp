#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <mutex>

// Enumeration for log levels
enum class LogLevel {
    INFO,
    WARN,
    ERROR,
    DEBUG
};

// Log class definition
class Logger {
public:
    // Static method to get the singleton instance
    static Logger& Instance() {
        static Logger instance;
        return instance;
    }

    // Method to set the log level filter
    void SetLogLevel(LogLevel level) {
        minLevel = level;
    }

    // Overloaded output operator for different log levels
    Logger& operator<<(const std::string& message) {
        if (currentLevel >= minLevel) {
            std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
            logStream << GetLogLevelString(currentLevel) << message << "\n";
        }
        return *this;
    }

    Logger& operator<<(LogLevel level) {
        currentLevel = level;
        return *this;
    }

    // Dump all logged messages and clear the buffer
    void Dump() {
        std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
        std::cout << logStream.str();
        logStream.str("");  // Clear the buffer
        logStream.clear();  // Reset the buffer's state
    }

    // Clear the buffer without dumping
    void Clear() {
        std::lock_guard<std::mutex> lock(mutex); // Ensure thread-safety
        logStream.str("");  // Clear the buffer
        logStream.clear();  // Reset the buffer's state
    }

private:
    // Private constructor for Singleton pattern
    Logger() : minLevel(LogLevel::INFO), currentLevel(LogLevel::INFO) {}

    // Deleted copy constructor and assignment operator
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    // Method to get the string representation of the log level
    std::string GetLogLevelString(LogLevel level) const {
        switch (level) {
            case LogLevel::INFO:    return "[INFO] ";
            case LogLevel::WARN:    return "[WARN] ";
            case LogLevel::ERROR:   return "[ERROR] ";
            case LogLevel::DEBUG:   return "[DEBUG] ";
            default:                return "[UNKNOWN] ";
        }
    }

    LogLevel minLevel;               // Minimum log level to filter messages
    LogLevel currentLevel;           // Current log level
    std::ostringstream logStream;    // Buffer to store log messages
    std::mutex mutex;                // Mutex for thread-safety
};

// Macro for easy logging with levels
#define LOG(level) Logger::Instance() << level

int main() {
    // Set log level to WARN, so INFO and DEBUG messages will be ignored
    Logger::Instance().SetLogLevel(LogLevel::WARN);

    LOG(LogLevel::INFO) << "This is an info message";   // Will not be logged
    LOG(LogLevel::WARN) << "This is a warning message";
    LOG(LogLevel::ERROR) << "This is an error message";

    // Dump all logs and clear the buffer
    Logger::Instance().Dump();

    // Logging after Dump to show that the buffer is cleared
    LOG(LogLevel::INFO) << "This info message will be ignored because of log level";
    LOG(LogLevel::DEBUG) << "This debug message will also be ignored";
    
    // Change log level to INFO to capture all messages
    Logger::Instance().SetLogLevel(LogLevel::INFO);
    
    // Log messages again
    LOG(LogLevel::INFO) << "Info message after log level change";
    LOG(LogLevel::DEBUG) << "Debug message after log level change";

    // Dump remaining logs
    Logger::Instance().Dump();

    return 0;
}
