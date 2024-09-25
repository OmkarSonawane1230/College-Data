// ======================================================================
// Name        : assign_3.cpp
// Author      : Omkar Sonawane
// Description : This program implements inheritance and exception 
//               handling.
// ======================================================================


#include <iostream>
#include <string>

using namespace std;

class Publication {
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}
    
    virtual void input() {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
        if (price < 0) throw invalid_argument("Price cannot be negative.");
    }

    virtual void display() {
        cout << "Title: " << title << "\nPrice: " << price << endl;
    }
};

class Book : public Publication {
    int pageCount;

public:
    Book() : pageCount(0) {}

    void input() {
        Publication::input();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (pageCount < 0) throw invalid_argument("Page count cannot be negative.");
    }

    void display() {
        Publication::display();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void input()  {
        Publication::input();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        if (playingTime < 0) throw invalid_argument("Playing time cannot be negative.");
    }

    void display()  {
        Publication::display();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter details for Book:\n";
        book.input();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
        book = Book(); // Resetting values to zero
    }

    try {
        cout << "\nEnter details for Tape:\n";
        tape.input();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
        tape = Tape(); // Resetting values to zero
    }

    cout << "\nBook Details:\n";
    book.display();
    cout << "\nTape Details:\n";
    tape.display();

    return 0;
}