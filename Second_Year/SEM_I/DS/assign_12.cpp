// ======================================================================
// Name        : assign_12.cpp
// Author      : Omkar Sonawane
// Description : This program implements Deque and its operations using
//               array.
// ======================================================================

#include <iostream>
#define SIZE 5

using namespace std;

class Deque {
    int arr[SIZE];
    int front;
    int rear;
    int count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at front.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }
        arr[front] = value;
        count++;
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full! Cannot insert at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        count++;
        cout << value << " inserted at the rear.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from front.\n";
            return;
        }

        cout << arr[front] << " deleted from the front.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        count--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty! Cannot delete from rear.\n";
            return;
        }

        cout << arr[rear] << " deleted from the rear.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }
        count--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Deque elements: ";
        for (int i = 0; i < count; i++) {
            cout << arr[(front + i) % SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

    int choice, value;

    while (true) {
        cout << "\nDeque Operations Menu:\n";
        cout << "1. Insert Front\n";
        cout << "2. Insert Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;

            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;

            case 3:
                dq.deleteFront();
                break;

            case 4:
                dq.deleteRear();
                break;

            case 5:
                dq.display();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}


/*


Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 1
Enter value to insert at front: 30

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 1
Enter value to insert at front: 23

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 2
Enter value to insert at rear: 19
19 inserted at the rear.

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 2
Enter value to insert at rear: 78
78 inserted at the rear.

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 5
Deque elements: 23 30 19 78 

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 3
23 deleted from the front.

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 4
78 deleted from the rear.

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 5
Deque elements: 30 19 

Deque Operations Menu:
1. Insert Front
2. Insert Rear
3. Delete Front
4. Delete Rear
5. Display Deque
6. Exit
Enter your choice: 6
Exiting...
*/