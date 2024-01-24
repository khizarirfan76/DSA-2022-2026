//Muhammad Khizar Irfan                       0248-BSCS-22                          E1
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int data) {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

class BST {
public:
    Node* headroot;

    BST() {
        headroot = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        insert(newNode, headroot);
    }

    void insert(Node*& newNode, Node*& root) {
        if (root == NULL) {
            root = newNode;
        } else if (newNode->data < root->data) {
            insert(newNode, root->right);
        } else {
            insert(newNode, root->left);
        }
    }

    void deleteval(int num) {
        deleteval(num, headroot);
    }

    void deleteval(int num, Node*& root)
    {
        if (root == NULL)
        {
            cout << "Value not found" << endl;
        }

        else if (num > root->data)
        {
            deleteval(num, root->right);
        }

        else if (num < root->data)
        {
            deleteval(num, root->left);
        }

        else if (num == root->data)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->right == NULL || root->left == NULL)
            {
                Node* temp = (root->right != NULL) ? root->right : root->left;
                delete root;
                root = temp;
            }

            else
            {
                Node* minimum = findMin(root->right);
                root->data = minimum->data;
                deleteval(minimum->data, root->right);
            }
        }
    }

    Node* findMin(Node* root)
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root;
    }

    void preOrder()
    {
        cout << "Preorder:" << endl;
        preOrder(headroot);
    }

    void preOrder(Node*& root)
    {
        if (root != NULL) {
            cout << root->data << endl;
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    bool checkTree()
    {
        bool flag = true;
        checkTree(headroot, flag);
        return flag;
    }

    void checkTree(Node*& root, bool& flag)
    {
        if (root == NULL) //iska matlab tree end hogya hai
        {
            return;
        }

        if ((root->left != NULL && root->left->data > root->data) ||   //checks condition of binary tree for left
            (root->right != NULL && root->right->data < root->data))  //checks condition of binary tree for right
        {
            flag = false;    //jaise hi aik bhi property violate ho false krke return
            return;
        }

        checkTree(root->left, flag);
        checkTree(root->right, flag);
    }

    BST mergeTree(BST tree1,BST tree2)
    {
        BST tree;
        tree.headroot=mergeTree(tree1.headroot,tree2.headroot);
        return tree;
    }
    Node* mergeTree(Node*& t1,Node*& t2)
    {
     if(!t1)
         return t2;
     if(!t2)
         return t1;

     t1->data+=t2->data;

        mergeTree(t1->left,t2->left);
        mergeTree(t1->right,t2->right);

    }


    int median(BST tree)
    {
        queue<int>* q = new queue<int>();
        int size = 0;

        median(tree.headroot, q, size);

        int* arr = new int[size];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = q->front();
            q->pop();
        }

        if (size % 2 == 1)
        {
            return arr[size / 2];
        }
        else
        {
            return (arr[size / 2 - 1] + arr[size / 2]) / 2;  // Corrected the formula
        }
    }

    void median(Node*& root,queue<int>*& q,int& size)
    {
        if(root!=NULL) {
            median(root->left, q, size);
            q->push(root->data);
            size++;
            median(root->right, q, size);
        }
    }
};



int main()
{
    BST tree1, tree2;

    // Insert elements into the first tree
    tree1.insert(4);
    tree1.insert(3);
    tree1.insert(1);
    tree1.insert(2);tree1.insert(7);



    // Insert elements into the second tree
    tree2.insert(1);
    tree2.insert(3);
    tree2.insert(5);


    // Calculate and print the median of the first tree only
    int medianValue = tree1.median(tree1);
    cout << "\nMedian of First Tree: " << medianValue << endl;

    return 0;
}