// ======================================================================
// Name        : assign_11.cpp
// Author      : Omkar Sonawane
// Description : This program implements Queue using array
// ======================================================================

#include <iostream>
#define MAX 10
using namespace std;

struct QueueData {
    int data[MAX];
    int front, rear;
};

class Queue {
    struct QueueData q;

public:
    Queue() {
        q.front = q.rear = -1;
    }

    bool isempty();
    bool isfull();

    void enqueue(int);
    int delqueue();
    void display();
};

// Check if the queue is empty
bool Queue::isempty() {
    return q.front == q.rear;
}

// Check if the queue is full
bool Queue::isfull() {
    return q.rear == MAX - 1;
}

// Insert an element into the queue
void Queue::enqueue(int x) {
    if (isfull()) {
        cout << "Queue Overflow!!!\n";
    } else {
        q.data[++q.rear] = x;
        if (q.front == -1) {
            q.front = 0; // First element inserted
        }
    }
}

// Delete an element from the queue
int Queue::delqueue() {
    if (isempty()) {
        cout << "Queue Underflow!!!\n";
        return -1; // Indicate error
    } else {
        int deletedValue = q.data[q.front++];
        // Reset front and rear when the queue becomes empty
        if (q.front > q.rear) {
            q.front = q.rear = -1;
        }
        return deletedValue;
    }
}

// Display all elements in the queue
void Queue::display() {
    if (isempty()) {
        cout << "Queue is Empty!!!\n";
    } else {
        cout << "Queue Contains: ";
        for (int i = q.front; i <= q.rear; ++i) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue obj;
    int ch, x;

    do {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "\nEnter the Data: ";
                cin >> x;
                obj.enqueue(x);
                break;

            case 2:
                x = obj.delqueue();
                if (x != -1) {
                    cout << "\nDeleted Element: " << x << endl;
                }
                cout << "\nRemaining Jobs: ";
                obj.display();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                cout << "\nExiting the Program...\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }
    } while (ch != 4);

    return 0;
}


/*



1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 1

Enter the Data: 120

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 1

Enter the Data: 233

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 1

Enter the Data: 877

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 1

Enter the Data: 766

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 2

Deleted Element: 120

Remaining Jobs: Queue Contains: 233 877 766 

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 2

Deleted Element: 233

Remaining Jobs: Queue Contains: 877 766 

1. Insert Job
2. Delete Job
3. Display
4. Exit
Enter your choice: 2

Deleted Element: 877

Remaining Jobs: Queue is Empty!!!
*/