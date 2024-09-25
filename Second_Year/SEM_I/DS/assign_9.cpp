// ======================================================================
// Name        : assign_9.cpp
// Author      : Omkar Sonawane
// Description : This program implements stack to check whether a string
//               is palindrome or not.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Stack {
    char* arr;
    int top, maxSize;

public:
    Stack(int size) : maxSize(size), top(-1) {
        arr = new char[maxSize];
    }

    void push(char ch) {
        if (top < maxSize - 1) {
            arr[++top] = ch;
        }
    }

    char pop() {
        if (top >= 0)
            return arr[top--];

        return '\0'; // Return null character if stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

class PalindromeChecker {
    string original;
    string cleaned; // Cleaned version for comparison

public:
    // Constructor to initialize the string
    PalindromeChecker(const string& str) : original(str) {
        preprocess();
    }

    void preprocess() {
        for (char ch : original) {
            if (isalnum(ch)) // Only consider alphanumeric characters
                cleaned += tolower(ch);
        }
    }

    // Function to get the reversed string
    string getReversed() {
        Stack stack(cleaned.length());
        for (char ch : cleaned) {
            stack.push(ch);
        }

        string reversed;
        while (!stack.isEmpty()) {
            reversed += stack.pop();
        }
        return reversed;
    }

    // Function to check if the string is a palindrome
    bool isPalindrome() {
        string reversed = getReversed();
        return cleaned == reversed;
    }

    void printOriginal() {
        cout << "\nOriginal String: " << original << endl;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    PalindromeChecker checker(input);
    checker.printOriginal();

    string reversed = checker.getReversed();
    cout << "\nReversed String: " << reversed << endl;

    if (checker.isPalindrome()) {
        cout << "\nThe string is a palindrome." << endl;
    } else {
        cout << "\nThe string is not a palindrome." << endl;
    }

    return 0;
}