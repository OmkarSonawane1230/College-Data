// ======================================================================
// Name        : assign_10.cpp
// Author      : Omkar Sonawane
// Description : This program implements Circular queue to manage pizza
//               orders.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
    string* queue;
    int front;
    int rear;
    int maxSize;

public:
    // Constructor to initialize the queue with a given size
    CircularQueue(int size) {
        maxSize = size;
        queue = new string[maxSize];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() const {
        return (rear + 1) % maxSize == front;
    }

    bool isEmpty() const {
        return front == -1;
    }

    // Add a new order to the queue
    void enqueue(const string& order) {
        if (isFull()) {
            cout << "Order queue is full! Cannot place more orders." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;  // First order in the queue
        }
        rear = (rear + 1) % maxSize;
        queue[rear] = order;
        cout << "Order placed: " << order << endl;
    }

    // Remove and serve the order at the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to serve!" << endl;
            return;
        }
        cout << "Serving order: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1;  // Queue is now empty
        } else {
            front = (front + 1) % maxSize;
        }
    }

    // Display all current orders in the queue
    void displayOrders() const {
        if (isEmpty()) {
            cout << "No current orders." << endl;
            return;
        }
        cout << "Current orders: ";
        int i = front;
        while (true) {
            cout << queue[i] << ", ";
            if (i == rear) break;
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};

int main() {
    int maxOrders;
    cout << "Enter the maximum number of orders the pizza parlor can accept: ";
    cin >> maxOrders;

    CircularQueue orders(maxOrders);
    int choice;
    string order;

    do {
        cout << "\n1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter your order: ";
                cin.ignore();  // Clear the newline character from the input buffer
                getline(cin, order);
                orders.enqueue(order);
                break;
            case 2:
                orders.dequeue();
                break;
            case 3:
                orders.displayOrders();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


/*

Enter the maximum number of orders the pizza parlor can accept: 5

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 1
Enter your order: Milk shake
Order placed: Milk shake

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 1
Enter your order: Ice cream
Order placed: Ice cream

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 1
Enter your order: Juice
Order placed: Juice

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 3
Current orders: Milk shake, Ice cream, Juice, 

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 2
Serving order: Milk shake

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 2
Serving order: Ice cream

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 2
Serving order: Juice

1. Place Order
2. Serve Order
3. Display Orders
4. Exit
Enter your choice: 4
Exiting the program.
 */