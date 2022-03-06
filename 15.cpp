#include <bits/stdc++.h>

using namespace std;
#define MAX 10000
class Stack
{
    int top;

public:
    int arr[MAX];

    Stack() { top = -1; }
    void push(int x);
    int pop();
    void peek(int i);
    bool isEmpty();
    void print();
};

bool Stack::isEmpty()
{
    return (top < 0);
}

void Stack::push(int x)
{
    if (top >= MAX - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        arr[++top] = x;
        cout << "The item " << x << " is pushed \n";
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << " Stack Underflow" << endl;
        return 0;
    }

    int val = arr[top];
    top--;
    return val;
}

void Stack::peek(int pos)
{
    int index = top - pos + 1;

    if (index < 0)
    {
        cout << "Invalid position \n";
        return;
    }

    else
        cout << "The value at the given position is " << arr[index] << endl;
}

void Stack::print()
{
    for (int i = top; i >=0 ; i--)
        cout << arr[i] << endl;
}

int main()
{
    class Stack s;
    int ch, key;
    char y;
    do
    {
        cout << "Enter 1 to push element" << endl
             << "Enter 2 to pop an element" << endl
             << "Enter 3 to peek an element" << endl
             << "Enter 4 to check if the stack is empty" << endl
             << "Enter 5 to print the stack" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element" << endl;
            cin >> key;
            s.push(key);
            break;

        case 2:
            cout << s.pop() << " popped" << endl;
            break;
        case 3:
            cout << "Enter position" << endl;
            cin >> key;
            s.peek(key);
            break;

        case 4:
            (s.isEmpty()) ? cout << "Stack empty" : cout << "Stack not Empty";
            cout << endl;
            break;

        case 5:
            s.print();
            break;

        default: cout<<"Wrong choice"<<endl;
        }
        cout<<"Press y to continue :::";
        cin>>y;
    }while(y=='y');

return 0;
}
