// ======================================================================
// Name        : assign_8.cpp
// Author      : Omkar Sonawane
// Description : This program implements a set operation using linked
//               list data structure.
// ======================================================================

#include <iostream>
using namespace std;

class Node {
public:
    int studentID;
    Node* next;

    Node(int id) : studentID(id), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void input() {
        int n, id;
        cout << "Enter number of student: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Student[" << i + 1 << "]: ";
            cin >> id;
            this->addStudent(id);
        }
    }

    void addStudent(int id) {
        Node* newNode = new Node(id);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    bool contains(int id) {
        Node* current = this->head;
        while (current != nullptr) {
            if (current->studentID == id) return true;
            current = current->next;
        }
        return false;
    }

    LinkedList unionSet(LinkedList& other) {
        LinkedList result;
        Node* current = this->head;
        while (current != nullptr) {
            result.addStudent(current->studentID);
            current = current->next;
        }
        current = other.head;
        while (current != nullptr) {
            if (!result.contains(current->studentID)) {
                result.addStudent(current->studentID);
            }
            current = current->next;
        }
        return result;
    }

    LinkedList intersection(LinkedList& other) {
        LinkedList result;
        Node* current = this->head;
        while (current != nullptr) {
            if (other.contains(current->studentID)) {
                result.addStudent(current->studentID);
            }
            current = current->next;
        }
        return result;
    }

    LinkedList difference(LinkedList& other) {
        LinkedList result;
        Node* current = this->head;
        while (current != nullptr) {
            if (!other.contains(current->studentID)) {
                result.addStudent(current->studentID);
            }
            current = current->next;
        }
        return result;
    }

    void printList() {
        Node* current = this->head;
        while (current != nullptr) {
            cout << current->studentID << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main(void) {
    LinkedList classList;
    LinkedList vanillaList;
    LinkedList butterscotchList;

    cout << "Enter Students in class: " << endl;
    classList.input();
    cout << "Enter Students who like Vanilla: " << endl;
    vanillaList.input();
    cout << "Enter Students who like Butterscotch: " << endl;
    butterscotchList.input();

    cout << "\nStudents in class: ";
    classList.printList();
    cout << "Students who like Vanilla: ";
    vanillaList.printList();
    cout << "Students who like Butterscotch: ";
    butterscotchList.printList();

    // Compute the required sets
    LinkedList bothLists = vanillaList.intersection(butterscotchList);
    LinkedList eitherLists = vanillaList.unionSet(butterscotchList);
    LinkedList neitherLists = classList.difference(eitherLists);

    // Display results
    cout << "\nStudents who like both vanilla and butterscotch: ";
    bothLists.printList() ;
    
    cout << "Students who like either vanilla or butterscotch or both: ";
    eitherLists.printList();

    cout << "students who like neither vanilla nor butterscotch: ";
    neitherLists.printList();

    return 0;
}