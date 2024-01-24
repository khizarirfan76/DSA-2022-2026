//created by Muhammad Khizar Irfan

#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    //not declaring height because we will use a dedicated function to calculate height live
    //for each node

    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class AVL
{
public:
    node* head;

    AVL()
    {
        head=NULL;
    }

    void insert(int data)
    {
        node* newNode=new node(data);
        insert(newNode,head);
    }

    void insert(node* newNode,node*& root)
    {
        if(root==NULL)
            root=newNode;
        else if (newNode->data>root->data)
            insert(newNode,root->right);
        else if (newNode->data<root->data)
            insert(newNode,root->left);

        int balance=getBalance(root);

        if(balance<-1 && newNode->data>root->right->data)
        {
            LeftRotate(root);//RR case
        }
        if(balance<-1 && newNode->data<root->right->data)
        {
            RightRotate(root->right);  //RL case
            LeftRotate(root);
        }
        if(balance>1 && newNode->data<root->left->data)
        {
            RightRotate(root); //LL case
        }
        if(balance>1 && newNode->data>root->left->data)
        {
            LeftRotate(root->left);  //LR case
            RightRotate(root);
        }


    }

    void RightRotate(node*& root)
    {
        node* a=root;
        node* b=root->left;
        node* c=b->right;

        b->right=a;
        a->left=c;
        root=b;
    }

    void LeftRotate(node*& root)
    {
        node* a=root;
        node* b=root->right;
        node* c=b->left;

        b->left=a;
        a->right=c;
        root=b;
    }

    int getBalance(node*& root)
    {
        return height(root->left)-height(root->right);
    }
    int height(node*& root)// this function works in such way that it goes to the leaf by recursion
    {                      //starts by calculating the height of leaf nodes and moves upwards and
                            //eventually calculates upto the given node;
        if(root==NULL)      //height of empty tree is zero
            return 0;

        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left,right);
    }

    int max(int a,int b)
    {
         return (a>b)? a:b;
    }

    void preOrder()
    {
        preOrder(head);
    }
    void preOrder(node* root)
    {
        if(root!=NULL)
        {
            cout << root->data<<endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }
};

int main()
{
    AVL tree;
    tree.insert(32);
    tree.insert(3);
    tree.insert(6);
    tree.insert(2);
    tree.insert(1);
    tree.insert(31);

    tree.preOrder();


}
