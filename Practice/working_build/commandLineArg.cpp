#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    cout << "arguments in Command Lines: " << endl;

    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }
    return 0;
}

// g++ commandLineArg.cpp -o commandLineArg hii hello how are you