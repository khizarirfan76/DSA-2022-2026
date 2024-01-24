#include <iostream>
using namespace std;

struct node
{
    int val;
    node* next;

    node(int value)
    {
        val=value;
        next= nullptr;
    }

};

struct queue
{
    node* head= nullptr;
    node* tail=nullptr;

    void enqueue(int val)
    {
        node* newNode=new node(val);

        if(head== nullptr)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode; //1/2tail and head wre at first pointing to the same memory location and by
            tail=newNode; //2/2tail->next=newNode we LINK THE MEMORY LOCATION itself to the newNode
        }
    }

    void dequeue()
    {
        if(head== nullptr)
        {
            cout<<"queue is empty"<<endl;

        }
        else
        {
           node* temp=head;
           head=head->next;
           delete(temp);
        }
    };
    void peek()
    {
        cout<<head->val<<endl;
    }
    bool empty()
    {
        return head== nullptr;
    }

};
int main()
{
    queue list;

    list.enqueue(5);
    list.enqueue(6);



    list.dequeue();
    list.dequeue();
    list.dequeue();

}