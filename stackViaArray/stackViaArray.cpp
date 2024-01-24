#include <iostream>
using namespace std;

struct stack
{
    int top;
    int* arr;
    int arraySize;

    stack(int size)
    {
        top=-1;
        arr=new int[size];
        arraySize=size;
    }
    stack()
    {
        top=-1;
        arr=new int[100];
    }
    void push(int value)
    {
        top++;        //remember to put this up because you want to increment before the testing in the if conditions
        if(top>arraySize-1)
        {
            cout<<"stack overflow";
            return;
        }

        arr[top]=value;

    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is empty";
            return;
        }
        top--;
    }
    bool empty()
    {
        return top==-1;
    }
    void peek()
    {
        cout<<arr[top];
    }

};

int main()
{
    stack stack(5);

    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(3);
    stack.push(7);
    stack.peek();
    stack.pop();
    stack.peek();





}