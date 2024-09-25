// ======================================================================
// Name        : assign_4.cpp
// Author      : Omkar Sonawane
// Description : This program implements operations of file handling
// ======================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
private:
    string filename;

public:
    FileHandler(string fname) : filename(fname) {}

    void writeToFile(string data) {
        // Open the file in append mode for output
        ofstream outputFile("example.txt", std::ios::app);
        if (!outputFile) {
            cerr << "Error creating file!" << endl;
            return;
        }
        
        outputFile << data << endl;
        outputFile.close();
    }

    void readFromFile() {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error opening file for reading!" << endl;
            return;
        }

        string line;
        while (getline(inFile, line)) {
            cout << line << endl;
        }

        inFile.close();
    }
};

int main() {
    FileHandler fileHandler("example.txt");

    // Write data to the file
    fileHandler.writeToFile("Hello, World!");
    fileHandler.writeToFile("This is a simple C++ file handling example.");
    fileHandler.writeToFile("Goodbye!");

    // Read data from the file
    cout << "Contents of the file: \n\n";
    fileHandler.readFromFile();

    return 0;
}


/**** File Opening Modes: ****/ 
/**
 * 1. Read Mode (std::ios::in):
 *    Opens a file for reading.
 *    If the file does not exist, it fails to open.
 *    std::ifstream inputFile("example.txt", std::ios::in);
 * 
 * 2. Write Mode (std::ios::out):
 *    Opens a file for writing. If the file already exists, its content is erased.
 *    std::ofstream outputFile("example.txt", std::ios::out);
 * 
 * 3. Append Mode (std::ios::app):
 *    Opens a file for writing, but new data is added to the end of the file.
 *    std::ofstream appendFile("example.txt", std::ios::app);
 * 
 * 4. Binary Mode (std::ios::binary):
 *    Can be used with both reading and writing modes.
 *    Opens a file in binary mode, useful for non-text files.
 *    std::ifstream binaryInput("example.bin", std::ios::binary);
 *    std::ofstream binaryOutput("example.bin", std::ios::binary);
 * 
 * 5. Read and Write Mode (std::ios::in | std::ios::out):
 *    Opens a file for both reading and writing.
 *    std::fstream readWriteFile("example.txt", std::ios::in | std::ios::out);
 * 
 * 6. Truncation Mode (std::ios::trunc):
 *    When used with write mode, it truncates the file to zero length if it already exists.
 *    std::ofstream truncFile("example.txt", std::ios::out | std::ios::trunc);
 * 
 */
