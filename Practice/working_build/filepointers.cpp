#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // ifstream file("exmaple.txt"); // seekp will not work
    // ofstream file("exmaple.txt"); // seekg will not work

    fstream file("example.txt", ios::in | ios::out);
    
    if (!file) {
        cerr << "Error opening file.\n";
        return 1;
    }
    
    char c;
    file.get(c);
    cout << "Character at current position: " << c << endl;
    
    // Move input pointer to 10th character from beginning
    file.seekg(10, ios::beg);

    file.get(c); // Read the character at the new position
    cout << "Character at position 10: " << c << endl;


    file.seekg(0, ios::beg);
    file.seekp(0, ios::beg);


    // Get the current position of the input pointer
    streampos position = file.tellg();
    cout << "Current position: " << position << endl << endl;

    while (file.get(c)) {
        cout << c;
    }

    file.close();

    return 0;
}