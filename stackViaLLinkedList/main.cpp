//Muhammad Khizar Irfan                     0248-BSCS-22                        E1
#include <iostream>
using namespace std;

//head is the bottom of the stack and tail is the top ,
// in popping be careful to make the pNextNode=nullptr of the node before the node being deleted

class node
{
public:
    int value;
    node* pNextNode;

    node()
    {

    }
    node(int value)
    {
        this->value=value;
        pNextNode=nullptr;
    }
};
struct stack
{
    node* head= nullptr;
    node* tail=nullptr;
    void push(int value)
    {
        node* newNode=new node(value);


        if(head== nullptr)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {

            tail->pNextNode=newNode;
            tail=newNode;

        }
    }

    void pop()
    {
        if(head== nullptr)
        {
            cout<<"the stack is empty"<<endl;
        }
        else
        {
            node* temp;
            temp=head;
            while(temp->pNextNode!=tail)
            {
                temp=temp->pNextNode;
            }
            node* temp2=tail;
            tail=temp;
            tail->pNextNode=nullptr;
            delete(temp2);

        }
    }

    void peak()
    {
        if(head== nullptr)
        {
            cout<<"stack is empty"<<endl;
        }
        else
        {
            cout<<head->value<<endl;
        }
    }

    void print()
    {
        node* temp;
        temp=head;

        while(temp->pNextNode!= nullptr)
        {
            cout<<temp->value<<endl;
            temp=temp->pNextNode;
        }
        cout<<temp->value<<endl;
    }
};

int main()
{
    stack stack;

    stack.push(4);
    stack.push(43);
    stack.push(43);
    stack.push(46);
    stack.push(42);

    stack.print();

    cout<<"--------------------------------"<<endl;

    stack.pop();

    stack.print();
}
