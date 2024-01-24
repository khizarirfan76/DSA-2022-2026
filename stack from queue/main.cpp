#include <iostream>
#include "queue.h"
#include "queue.cpp"
#include "node.h"
#include "node.cpp"
#include "stack.h"
#include "stack.cpp"

class stack      //stack using queue
{
public:
    Queue<int> q1;
    Queue<int> q2;

    void enqueue(int data)
    {
        q2.enqueue(data);

        while(!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }

        Queue<int> q;
        q=q1;
        q1=q2;
        q2=q;
    }

    void pop()
    {
        cout<<q1.dequeue();
        cout<<endl;
    }
};

class queue //queue using stack
{
public:
    Stack<int> s1;

    void push(int data)
    {
        s1.push(data);
    }
    void pop()
    {
        Stack<int> s2;

        while (!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        cout<<s2.pop();
        while (!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
    }


};

int main()
{

}
