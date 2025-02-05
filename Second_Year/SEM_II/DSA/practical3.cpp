#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int flag;
    Node* down;
    Node* next;
    
    Node(string n, int f) : name(n), flag(f), down(nullptr), next(nullptr) {}
};

using BName = const string&;
using CName = const string&;
using SName = const string&;
using SSName = const string&;
using NName = const string&;

class BookTree {
    Node* root;
public:
    BookTree() : root(new Node("", 0)) {}

    void createBook(BName name) {
        if (findNode(root, name, -1) != nullptr) {
            cout << "Book already exists. Please create a new book with a different name.\n";
            return;
        }
        addNode(root, name, -1);
        cout << "Book created successfully.\n";
    }

    void createChapter(BName bookName, CName chapterName) {
        Node* book = findNode(root, bookName, -1);
        if (book == nullptr) {
            cout << "Book not found. Please create the book first.\n";
            return;
        }
        if (findNode(book, chapterName, 0) != nullptr) {
            cout << "Chapter already exists.\n";
            return;
        }
        addNode(book, chapterName, 0);
        cout << "Chapter created successfully.\n";
    }

    void createSection(BName bookName, CName chapterName, SName sectionName) {
        Node* book = findNode(root, bookName, -1);
        if (book == nullptr) {
            cout << "Book not found. Please create the book first.\n";
            return;
        }
        Node* chapter = findNode(book, chapterName, 0);
        if (chapter == nullptr) {
            cout << "Chapter not found. Please create the chapter first.\n";
            return;
        }
        if (findNode(chapter, sectionName, 1) != nullptr) {
            cout << "Section already exists.\n";
            return;
        }
        addNode(chapter, sectionName, 1);
        cout << "Section created successfully.\n";
    }

    void createSubsection(BName bookName, CName chapterName, SName sectionName, SSName subsectionName) {
        Node* book = findNode(root, bookName, -1);
        if (book == nullptr) {
            cout << "Book not found. Please create the book first.\n";
            return;
        }
        Node* chapter = findNode(book, chapterName, 0);
        if (chapter == nullptr) {
            cout << "Chapter not found. Please create the chapter first.\n";
            return;
        }
        Node* section = findNode(chapter, sectionName, 1);
        if (section == nullptr) {
            cout << "Section not found. Please create the section first.\n";
            return;
        }
        if (findNode(section, subsectionName, 2) != nullptr) {
            cout << "Subsection already exists.\n";
            return;
        }
        addNode(section, subsectionName, 2);
        cout << "Subsection created successfully.\n";
    }
    
    Node* findNode(Node* parent, NName nodeName, int flag) {
        Node* node = parent->down;
        while (node != nullptr) {
            if (node->name == nodeName && node->flag == flag) {
                return node;
            }
            node = node->next;
        }
        return nullptr;
    }

    void addNode(Node* parent, NName nodeName, int flag) {
        Node* newNode = new Node(nodeName, flag);
        if (parent->down == nullptr) {
            parent->down = newNode;
        } else {
            Node* temp = parent->down;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printTree(Node* root, int level = 0) {
        if (root == nullptr)
            return;

        // Indentation based on the level in the tree
        cout << string(level * 3, ' ');

        // Print the current node based on its type (book, chapter, section, or subsection)
        if (root->flag == -1) {
            cout << "Book: " << root->name << endl;
        } else if (root->flag == 0) {
            cout << "- " << root->name << endl;
        } else if (root->flag == 1) {
            cout << "- " << root->name << endl;
        } else if (root->flag == 2) {
            cout << "- " << root->name << endl;
        }

        // Recursively print the down pointer (children)
        printTree(root->down, level + 1);
        
        // Recursively print the next pointer (siblings)
        printTree(root->next, level);
    }

    void printBook(const string& bookName) {
        Node* book = root->down;
        while (book != nullptr) {
            if (book->name == bookName && book->flag == -1) {
                printTree(book);
                return;
            }
            book = book->next;
        }
        cout << "Book not found.\n";
    }

    ~BookTree() {
        delete root;
    }
};

int main() {
    BookTree bookTree;
    int choice;
    string bookName, chapterName, sectionName, subsectionName;
    int chapterChoice, sectionChoice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Create Book\n";
        cout << "2. Create Chapter\n";
        cout << "3. Create Section\n";
        cout << "4. Create Subsection\n";
        cout << "5. Print Book Structure\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // To handle leftover newline character after integer input
        
        switch (choice) {
            case 1:
                cout << "Enter Book Name: ";
                getline(cin, bookName);
                bookTree.createBook(bookName);
                break;

            case 2:
                cout << "Enter Book Name: ";
                getline(cin, bookName);
                cout << "Enter Chapter Name: ";
                getline(cin, chapterName);
                bookTree.createChapter(bookName, chapterName);
                break;

            case 3:
                cout << "Enter Book Name: ";
                getline(cin, bookName);
                cout << "Enter Chapter Name: ";
                getline(cin, chapterName);
                cout << "Enter Section Name: ";
                getline(cin, sectionName);
                bookTree.createSection(bookName, chapterName, sectionName);
                break;

            case 4:
                cout << "Enter Book Name: ";
                getline(cin, bookName);
                cout << "Enter Chapter Name: ";
                getline(cin, chapterName);
                cout << "Enter Section Name: ";
                getline(cin, sectionName);
                cout << "Enter Subsection Name: ";
                getline(cin, subsectionName);
                bookTree.createSubsection(bookName, chapterName, sectionName, subsectionName);
                break;

            case 5:
                cout << "Enter Book Name: ";
                getline(cin, bookName);
                bookTree.printBook(bookName);
                break;

            case 6:
                cout << "Exiting the program...\n";
                return 0;

            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
}