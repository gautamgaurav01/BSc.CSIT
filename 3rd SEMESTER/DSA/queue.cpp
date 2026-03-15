#include <iostream>
#define MAX 5

using namespace std;

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value)
{
    if (rear == MAX - 1)
    {
        cout << "Queue Overflow" << endl;
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = value;
    cout << "Inserted "<< endl;
}

int dequeue()
{
    if (front == -1)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    int x = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return x;
}

int isFull()
{
    return rear == MAX - 1;
}

int isEmpty()
{
    return rear == front == -1;
}

int peek()
{
    return queue[front];
}

void display()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements: " <<endl;
    for (int i = front; i <= rear; i++)
    {
        cout << queue[i] << endl;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    cout << "Dequeued: " << dequeue() << endl;
    display(); 

    cout << "Peeked Value: " << peek() << endl;

    return 0;
}