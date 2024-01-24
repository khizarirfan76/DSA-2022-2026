#include <iostream>
using namespace std;

struct node
{
    int value;
    node* next;
    node()
    {

    }
    node(int value)
    {
        this->value=value;
        next=nullptr;
    }
};

struct linkedList
{
    node* head=nullptr;

    void add(int value)
    {
        node* newNode=new node(value);

        if(head==nullptr)
        {
            head=newNode;
        }
        else
        {
            node* temp=new node();
            temp=head;

            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }

            temp->next=newNode;
        }
    }

    void printList()
    {
        node* temp=new node();
        temp=head;

        while(temp->next!=nullptr)
        {
            cout<<temp->value<<endl;
            temp=temp->next;

        }
    }
    void remove(int index)
    {
        
    }
};
int main()
{

}
