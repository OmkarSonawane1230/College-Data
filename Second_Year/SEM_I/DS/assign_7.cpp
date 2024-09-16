//============================================================================
// Name        : Omkar Sonawane
// Author      : gaur
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

struct node {
    int PRN;
    char name[20];
    node* next;
};

class club {
    int num, cnt;
    char nm[20];
    node* head;

public:
    club() : num(0), cnt(0), head(nullptr) {}  // Use initializer list

    node* create();
    void display(node*) const;
    node* conct(node*, node*);
    void reverse(node*) const;
    node* insert_president(node*);
    void insert_sect(node*);
    void insert_member(node*);
    node* del_president(node*);
    node* del_secretary(node*);
    node* del_member(node*);
};

node* club::create() {
    node *temp, *n1;
    temp = n1 = nullptr;
    cout << "How many student data do you want to enter: " << endl;
    cin >> cnt;
    while (cnt > 0) {
        n1 = new node;
        cout << "Enter the PRN number of students: " << endl;
        cin >> num;
        n1->PRN = num;
        cout << "Enter the name of students: " << endl;
        cin >> nm;
        strcpy(n1->name, nm);
        n1->next = nullptr;
        if (head == nullptr) {
            head = n1;
            temp = head;
        } else {
            temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = n1;
        }
        cnt--;
    }
    return head;
}

void club::display(node* head) const {
    node* temp = head;
    while (temp != nullptr) {
        if (temp->next == nullptr) {
            cout << "[" << temp->PRN << "|" << temp->name << "] -> NULL";
        } else {
            cout << "[" << temp->PRN << "|" << temp->name << "] -> ";
        }
        temp = temp->next;
    }
    cout << endl;  // For cleaner output formatting
}

node* club::conct(node* head1, node* head2) {
    node *head3, *temp;
    head3 = head1;
    if (head1 == nullptr) return head2;
    temp = head1;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = head2;
    return head3;
}

void club::reverse(node* head) const {
    if (head == nullptr) return;
    reverse(head->next);
    cout << "[" << head->PRN << "|" << head->name << "] -> ";
}

node* club::insert_president(node* head) {
    node *n2 = new node;
    cout << "\nEnter the PRN number of President: ";
    cin >> n2->PRN;
    cout << "\nEnter the name of President: ";
    cin >> n2->name;
    n2->next = head;
    head = n2;
    return head;
}

void club::insert_member(node* head) {
    node *temp = head, *n2 = new node;
    int pn;
    cout << "\nEnter the PRN number of Member: ";
    cin >> n2->PRN;
    cout << "\nEnter the name of Member: ";
    cin >> n2->name;
    n2->next = nullptr;
    cout << "\nEnter the PRN number after which you want to add this member: ";
    cin >> pn;

    while (temp != nullptr) {
        if (temp->PRN == pn) {
            n2->next = temp->next;
            temp->next = n2;
            cout << "\n\nMember added successfully....!!";
            return;
        }
        temp = temp->next;
    }
    cout << "\n\nMember with given PRN not found!";
}

void club::insert_sect(node* head) {
    node *temp = head, *n2 = new node;
    cout << "\nEnter the PRN number for Secretary: ";
    cin >> n2->PRN;
    cout << "\nEnter the name for Secretary: ";
    cin >> n2->name;
    n2->next = nullptr;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = n2;
}

node* club::del_president(node* head) {
    if (head == nullptr) return nullptr;
    node* temp = head;
    head = head->next;
    delete temp;  // Use delete instead of free for C++ new
    return head;
}

node* club::del_secretary(node* head) {
    if (head == nullptr) return nullptr;
    node *temp = head, *t1 = nullptr;
    while (temp->next != nullptr) {
        t1 = temp;
        temp = temp->next;
    }
    if (t1 != nullptr) {
        t1->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;  // Use delete instead of free for C++ new
    return head;
}

node* club::del_member(node* head) {
    if (head == nullptr) return nullptr;
    node *temp = head, *t1 = nullptr;
    int pn;
    cout << "\nEnter the PRN number of the member to delete: ";
    cin >> pn;
    while (temp != nullptr) {
        if (temp->next != nullptr && temp->next->PRN == pn) {
            t1 = temp->next;
            temp->next = t1->next;
            delete t1;  // Use delete instead of free for C++ new
            cout << "\n\nMember removed successfully....!!";
            return head;
        }
        temp = temp->next;
    }
    cout << "\n\nMember with given PRN not found!";
    return head;
}

int main() {
    club c1, c2, c3;
    node* h1 = nullptr;
    node* h2 = nullptr;
    node* h3 = nullptr;
    int ch;

    cout << "\n\t!!!Group B: Assignment No:01!!!" << endl;  // prints !!!Assignment number and group!!!
    do {
        cout << "\n\n1. Enter data of SE A Division:";
        cout << "\n2. Enter data of SE B Division:";
        cout << "\n3. Concatenation of Lists..";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\n\nPlease enter the student info who is a registered member.." << endl;
                cout << "\n\nEnter the Panclub Data of SE A Division:\n" << endl;
                h1 = c1.create();
                cout << "SE Comp Division A list is as follows: " << endl;
                c1.display(h1);
                cout << "\n\nReverse List of SE Div A:\n\n";
                c1.reverse(h1);
                c1.insert_sect(h1);
                cout << "\n\nAfter insertion of Secretary:\n";
                c1.display(h1);
                h1 = c1.insert_president(h1);
                cout << "\n\nAfter insertion of President:\n\n";
                c1.display(h1);
                c1.insert_member(h1);
                cout << "\n\nAfter insertion of Members:\n\n";
                c1.display(h1);
                h1 = c1.del_president(h1);
                cout << "\n\nAfter deletion of President:\n\n";
                c1.display(h1);
                h1 = c1.del_secretary(h1);
                cout << "\n\nAfter deletion of Secretary:\n\n";
                c1.display(h1);
                h1 = c1.del_member(h1);
                cout << "\n\nAfter deletion of Member:\n\n";
                c1.display(h1);
                break;

            case 2:
                cout << "\n\nPlease enter the student info who is a registered member.." << endl;
                cout << "\n\nEnter the Panclub Data of SE B Division:\n" << endl;
                h2 = c2.create();
                cout << "SE Comp Division B list is as follows: " << endl;
                c2.display(h2);
                cout << "\n\nReverse List of SE Div B:\n\n";
                c2.reverse(h2);
                c2.insert_sect(h2);
                cout << "\n\nAfter insertion of Secretary:\n";
                c2.display(h2);
                h2 = c2.insert_president(h2);
                cout << "\n\nAfter insertion of President:\n\n";
                c2.display(h2);
                c2.insert_member(h2);
                cout << "\n\nAfter insertion of Members:\n\n";
                c2.display(h2);
                h2 = c2.del_president(h2);
                cout << "\n\nAfter deletion of President:\n\n";
                c2.display(h2);
                h2 = c2.del_secretary(h2);
                cout << "\n\nAfter deletion of Secretary:\n\n";
                c2.display(h2);
                h2 = c2.del_member(h2);
                cout << "\n\nAfter deletion of Member:\n\n";
                c2.display(h2);
                break;

            case 3:
                h3 = c3.conct(h1, h2);
                cout << "\n\nThe concatenation of Div: A and Div: B of SE Comp Class is as follows:\n\n";
                c3.display(h3);
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (ch != 4);

    // Free allocated memory
    while (h1 != nullptr) {
        node* temp = h1;
        h1 = h1->next;
        delete temp;
    }
    while (h2 != nullptr) {
        node* temp = h2;
        h2 = h2->next;
        delete temp;
    }
    while (h3 != nullptr) {
        node* temp = h3;
        h3 = h3->next;
        delete temp;
    }

    return 0;
}