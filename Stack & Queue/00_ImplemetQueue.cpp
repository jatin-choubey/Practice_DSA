#include <iostream>
using namespace std;

// Include necessary header files

class Queue
{
private:
    int front, rear, maxSize; // Declare private variables for the front, rear, and maximum size of the queue
    int *arr;                 // Declare a dynamic integer array to store the queue elements

public:
    Queue(int size)
    { // Constructor to initialize the Queue with a given size
        maxSize = size;
        arr = new int[maxSize]; // Dynamically allocate memory for the array
        front = rear = -1;      // Initialize front and rear to -1 to indicate an empty queue
    }

    ~Queue()
    { // Destructor to free the dynamically allocated memory
        delete[] arr;
    }

    bool isEmpty()
    { // Check if the queue is empty
        return front == -1;
    }

    bool isFull()
    {                                         // Check if the queue is full
        return (rear + 1) % maxSize == front; // Circular queue logic
    }

    void enqueue(int data)
    { // Add an element to the queue (enqueue operation)
        if (isFull())
        { // Check if the queue is full
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        if (isEmpty())
        { // If the queue is empty, set front and rear to 0
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % maxSize; // Circularly increment rear
        }
        arr[rear] = data; // Add the data to the rear of the queue
    }

    void dequeue()
    { // Remove an element from the queue (dequeue operation)
        if (isEmpty())
        { // Check if the queue is empty
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        if (front == rear)
        { // If there's only one element in the queue, reset front and rear
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % maxSize; // Circularly increment front
        }
    }

    int peek()
    { // Get the front element of the queue (peek operation)
        if (isEmpty())
        { // Check if the queue is empty
            cout << "Queue is empty. Cannot peek." << endl;
            return -1;
        }
        return arr[front]; // Return the element at the front of the queue
    }
};

int main()
{
    Queue q(5); // Create a queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();

    cout << "Front element after dequeue: " << q.peek() << endl;

    return 0;
}
