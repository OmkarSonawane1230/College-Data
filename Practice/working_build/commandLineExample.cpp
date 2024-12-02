#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments were passed
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    // Get input and output file names from command line arguments
    string input_filename = argv[1];
    string output_filename = argv[2];

    // Open input file
    ifstream input_file(input_filename);
    if (!input_file) {
        cerr << "Error: Could not open input file " << input_filename << endl;
        return 1;
    }

    // Open output file
    ofstream output_file(output_filename);
    if (!output_file) {
        cerr << "Error: Could not open output file " << output_filename << endl;
        return 1;
    }

    // Read data from input file and write to output file
    string line;
    while (getline(input_file, line)) {
        output_file << line << endl;
    }

    // Close the files
    input_file.close();
    output_file.close();

    cout << "File copied successfully from " << input_filename << " to " << output_filename << endl;

    return 0;
}
