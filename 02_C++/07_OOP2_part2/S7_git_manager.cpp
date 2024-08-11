#include <iostream>
#include <map>
#include <vector>
#include <string>

class SimpleGitManager {
public:
    // Constructor
    SimpleGitManager() : commitIndex(0) {
        std::cout << "Git repository has been created." << std::endl;
    }

    // Initialize the repository
    void initialize() {
        stage.clear();       // Clear the staging area
        history.clear();     // Clear commit history
        commitIndex = 0;     // Reset commit index
        std::cout << "Repository initialized." << std::endl;
    }

    // Stage a file for commit
    void stageFile(const std::string& fileName) {
        stage.push_back(fileName);
        std::cout << "Staged file: " << fileName << std::endl;
    }

    // Commit the staged files
    void makeCommit(const std::string& commitMessage) {
        if (stage.empty()) {
            std::cout << "No files staged for commit." << std::endl;
            return;
        }

        history[commitIndex++] = {commitMessage, stage};
        stage.clear(); // Clear the staging area after commit
        std::cout << "Committed with message: \"" << commitMessage << "\"" << std::endl;
    }

    // Display the status of the repository
    void showStatus() const {
        std::cout << "Files staged for commit:" << std::endl;
        if (stage.empty()) {
            std::cout << "  None" << std::endl;
        } else {
            for (const auto& file : stage) {
                std::cout << "  " << file << std::endl;
            }
        }

        std::cout << "Commit History:" << std::endl;
        if (history.empty()) {
            std::cout << "  No commits yet." << std::endl;
        } else {
            for (const auto& commit : history) {
                std::cout << "Commit " << commit.first << ": " << commit.second.first << std::endl;
                std::cout << "  Files:" << std::endl;
                for (const auto& file : commit.second.second) {
                    std::cout << "    " << file << std::endl;
                }
            }
        }
    }

private:
    std::vector<std::string> stage; // Files staged for commit
    std::map<int, std::pair<std::string, std::vector<std::string>>> history; // Commit history
    int commitIndex; // Index for the next commit
};

int main() {
    SimpleGitManager gitManager;

    gitManager.initialize();
    gitManager.stageFile("file1.txt");
    gitManager.stageFile("file2.txt");
    gitManager.makeCommit("Initial commit");

    gitManager.stageFile("file3.txt");
    gitManager.makeCommit("Added file3");

    gitManager.showStatus();

    return 0;
}
