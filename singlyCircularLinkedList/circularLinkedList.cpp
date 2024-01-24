#include <iostream>
using namespace std;

struct node
{
    int value;
    node* pNextNode;

    node()
    {
        value=0;
        pNextNode= nullptr;
    }
    node(int value)
    {
        this->value=value;
        pNextNode= nullptr;
    }

};

struct circularLinkedList
{
    node* pHead= nullptr;

    void add(int value)
    {
        node* newNode=new node(value);
        if (pHead->pNextNode== nullptr)
        {
            pHead=newNode;
            pHead->pNextNode=pHead;

        }
        else
        {
            node* temp=new node();
            temp=pHead;
            while(temp->pNextNode!=pHead)
            {
                temp=temp->pNextNode;
            }
            temp->pNextNode=newNode;
            newNode->pNextNode=pHead;
        }

    }

    void printlist()
    {
        node* temp=new node();
        temp=pHead;
        do {
            cout<<temp->value<<endl;
            temp=temp->pNextNode;
        }
        while(temp!=pHead);
    }

    circularLinkedList()
    {
        pHead=new node();


    }


};

int main()
{
    circularLinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    list.printlist();

}