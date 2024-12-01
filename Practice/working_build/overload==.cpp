#include <iostream>
#include <cstring>
using namespace std;

class String {
    const char *str;
public:
    String(const char *s) : str(s) {}

    bool operator==(String &other) {
        return (strcmp(str, other.str) == 0) ? true : false;
    }
};

int main() {

    String s = String("hello");
    String a = String("hehllo");

    if (s == a) {
        cout << "Yes.." << endl;
    } else {
        cout << "No.." << endl;
    }
    return 0;
}