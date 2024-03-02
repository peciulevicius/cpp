#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cerrno>

int main() {
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::cin >> filename;

    std::ifstream file(filename.c_str());

    if (!file) {
        std::cerr << "Unable to open " << filename << " Error: " << strerror(errno) << '\n';
        return 1;
    }

    std::cout << "Successfully opened: " << filename << '\n';

    std::string line, longestWord;
    int maxWordLength = 0;
    std::string fileContent;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;

        // Print the line, regardless of whitespace content
        std::cout << "Read line: " << line << '\n';

        // Find the longest word in the current line
        while (iss >> word) {
            if (word.length() > maxWordLength) {
                longestWord = word;
                maxWordLength = word.length();
            }
        }

        // Print the longest word if the line is not empty
        if (!line.empty()) {
            std::cout << "Longest word in line: '" << line << "' is '" << longestWord << "'\n";
        }

        // Add the line to the file content
        fileContent += line + "\n";

        // Reset variables for the next line
        longestWord = "";
        maxWordLength = 0;
    }

    // Print the entire file content
    std::cout << "File content: \n" << fileContent << '\n';

    file.close();
    return 0;
}