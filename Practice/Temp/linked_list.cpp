#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class LinkedList {
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void addValue(int val) {
        Node *info = new Node();
        Node *temp = head;

        
        info->data = val;
        info->next = nullptr;

        if (head == nullptr) {
            head = info;
            temp = head;
        } else {
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = info;
        }
    }

    void display() {
        Node *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << endl;
    }

};

int main() {
    LinkedList obj;

    obj.addValue(5);
    obj.addValue(7);
    obj.addValue(2);

    obj.display();
    return 0;
}