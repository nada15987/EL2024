#include <iostream>
#include <stack>
#include <string>
#include <memory>  // For smart pointers

class FunctionTracer {
public:
    // Constructor logs the entry into a function
    FunctionTracer(const std::string& funcName) : funcName(funcName) {
        callStack.push(funcName);
        std::cout << "Enter to " << funcName << std::endl;
    }

    // Destructor logs the exit from a function
    ~FunctionTracer() {
        if (!callStack.empty() && callStack.top() == funcName) {
            std::cout << "Exit from " << funcName << std::endl;
            callStack.pop();
        }
    }

    // Print the current backtrace of function calls
    static void printBacktrace() {
        std::cout << "\nBacktrace as follows:" << std::endl;
        std::stack<std::string> tempStack = callStack;
        int level = 0;
        while (!tempStack.empty()) {
            std::cout << level++ << " - " << tempStack.top() << std::endl;
            tempStack.pop();
        }
        std::cout << "Backtrace is finished\n" << std::endl;
    }

private:
    std::string funcName; // Name of the function being traced
    static inline std::stack<std::string> callStack; // Stack to store function call history
};

// Functions with tracing
void func3() {
    FunctionTracer trace("func3");
    try {
        // Function logic 
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
}

void func2() {
    FunctionTracer trace("func2");
    try {
        func3();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
}

void func1() {
    FunctionTracer trace("func1");
    try {
        func2();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }
}

int main() {
    FunctionTracer trace("main");
    try {
        func1();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw;
    }

    return 0;
}




/*
//another method
#include <iostream>
#include <stack>
#include <string>
#include <stdexcept> // For std::runtime_error

class FunctionTracer {
public:
    // Constructor logs the entry into a function
    FunctionTracer(const std::string& funcName) 
        : funcName(funcName) {
        callStack.push(funcName);
        std::cout << "Enter to " << funcName << std::endl;
    }

    // Destructor logs the exit from a function
    ~FunctionTracer() {
        if (!callStack.empty() && callStack.top() == funcName) {
            std::cout << "Exit from " << funcName << std::endl;
            callStack.pop();
        }
    }

    // Print the current backtrace of function calls
    static void printBacktrace() {
        std::cout << "\nBacktrace as follows:" << std::endl;
        std::stack<std::string> tempStack = callStack;
        int level = 0;
        while (!tempStack.empty()) {
            std::cout << level++ << " - " << tempStack.top() << std::endl;
            tempStack.pop();
        }
        std::cout << "Backtrace is finished\n" << std::endl;
    }

private:
    std::string funcName; // Name of the function being traced
    static inline std::stack<std::string> callStack; // Stack to store function call history
};

// Functions with tracing
void func3() {
    FunctionTracer trace("func3");
    try {
        // Function logic (add your code here)
        // Simulate an exception
        throw std::runtime_error("Exception in func3");
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw; // Rethrow to allow further handling
    }
}

void func2() {
    FunctionTracer trace("func2");
    try {
        func3();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw; // Rethrow to allow further handling
    }
}

void func1() {
    FunctionTracer trace("func1");
    try {
        func2();
    } catch (...) {
        FunctionTracer::printBacktrace();
        throw; // Rethrow to allow further handling
    }
}

int main() {
    FunctionTracer trace("main");
    try {
        func1();
    } catch (...) {
        FunctionTracer::printBacktrace();
        // Handle or log the final exception here, if needed
    }

    return 0;
}
*/