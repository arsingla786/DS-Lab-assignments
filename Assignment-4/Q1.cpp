#include <iostream>
using namespace std;

#define MAX 5  // maximum size of queue

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == MAX - 1);
    }

    // Add element to queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (front == -1) front = 0; // first insertion
        arr[++rear] = x;
        cout << x << " enqueued into queue." << endl;
    }

    // Remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        if (front == rear) {  // last element removed
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Peek (front element)
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    // Display queue contents
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Menu-driven main function
int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << (q.isEmpty() ? "Queue is Empty" : "Queue is not Empty") << endl;
                break;
            case 6:
                cout << (q.isFull() ? "Queue is Full" : "Queue is not Full") << endl;
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
 

//queue 


#include <iostream>
using namespace std;
#define MAX 5
int front = -1;
int rear  = -1;
int queue[MAX];

void enqueue(int data){
    if(rear == MAX-1){
        cout<<"queue overflow!"<<endl;
    }
    else{
    if(front==-1){
        front=0; //first element
    }
    rear ++;
    queue[rear] = data;
}
}
void dequeue(){
    if(front == -1 || front >rear){
        cout<<"underflow!"<<endl;
    }
    else{
    front++;
    if(front>rear){//reset queue
        front=rear=-1;
    }
    }
}
 
void display(){
    if(front==-1){
        cout<<"empty queue!"<<endl;
        return;
    }
    for(int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
    }
    cout<<endl;
}
void isFull(){
    if(rear==MAX-1){
        cout<<"queue full"<<endl;
    }
    else{
        cout<<"not full"<<endl;
    }
}
void isEmpty(){
    if(front==rear){
        cout<<"yes empty"<<endl;
    }
    else{
        cout<<"not empty"<<endl;
    }
}
int main()
{
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    display();
    isFull();
    isEmpty();
    dequeue();
    dequeue();
    dequeue();
    dequeue(); 
 
    display();
}


//circular queue 
#include <iostream>
using namespace std;
#define MAX 5
int front = -1;
int rear  = -1;
int queue[MAX];

void enqueue(int data){
    if ((rear + 1) % MAX == front) {
        cout << "Overflow" << endl;
        return;
    }
    if (front == -1) { // inserting the first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = data;  // <-- always store the element
}

void dequeue(){
    if (front == -1) {
        cout << "Underflow" << endl;
        return;
    }
    cout << "Dequeued: " << queue[front] << endl;
    if (front == rear) {
        // queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;        // stop when we reach rear
        i = (i + 1) % MAX;           // move circularly
    }
    cout << endl;
}

int main() {
    enqueue(40);
    display();

    enqueue(30);
    enqueue(20);
    display();

    dequeue();
    display();

    enqueue(50);
    enqueue(60);
    enqueue(70); // overflow if full
    display();
}
