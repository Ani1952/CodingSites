#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{

    Node *Rear, *Front;

public:
    Queue()
    {
        Rear = Front = NULL;
    }
    void nq(int);
    void dq();
    int front();
    int rear();
    bool empty();
    void dis();
};

bool Queue::empty()
{
    if (Front == NULL)
        return false;
    else
        return false;
}

void Queue::nq(int data)
{
    Node *temp = new Node(data);
    if (Rear == NULL)
    {
        Rear = Front = temp;
        return;
    }

    Rear->next = temp;
    Rear = temp;
}

void Queue::dq()
{
    Node *temp = Front;

    if (Front == NULL)
        return;
    Front = Front->next;
    if (Front == NULL)
        Rear = NULL;
    delete (temp);
}

int Queue::front()
{
    if (Front == NULL)
        return -1;
    return (Front->data);
}
int Queue::rear()
{
    if (Front == NULL)
        return -1;
    return (Rear->data);
}

void Queue::dis()
{
    Node *temp = Front;
    while (temp != NULL)
    {
        cout << "<-" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    class Queue q;
    q.nq(1);
    q.nq(2);
    q.nq(3);
    q.nq(4);
    q.nq(5);
    q.nq(6);
    q.nq(7);
    q.nq(8);

    q.dis();
    
    q.dq();
    q.dq();

    q.dis();

    cout<<q.front()<<endl<<q.rear()<<endl;
    return 0;
}