#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int current;
    int size;
    int* arr;

    void swap(int& a,int& b)
    {
        int c=a;
        a=b;
        b=c;
    }

public:
    MaxHeap(int size)
    {
        this->size=size;
        current=0;
        arr=new int[size];
    }

    void insert(int data)
    {
        if(current>=size)
        {
            cout<<"heap full"<<endl;
            return;
        }
        arr[current]=data;
        int i=current;
        while (i!=0)       //to find the parent of any index use (i-1)/2 and if we keep doing this we will
        {                  //eventually reach the root/arr[0]
            if(arr[i]>arr[(i-1)/2])
                swap(arr[i],arr[(i-1)/2]);

            i=(i-1)/2;
        }
        current++;
    }

    int remove()
    {
        current--;
        int root=arr[0];
        arr[0]=arr[current];
        int i=0;
        while (true)
        {
            int root=i;       //acts as head in respective iteration
            int left=(2*i)+1;
            int right=(2*i)+2;

            int large=root;   //we assume keh heap property is maintained and root index is the larger than childs

            if(arr[root]<arr[left])    //if left is bigger then we swap and make left index the larger
            {
                swap(arr[root],arr[left]);
                large=left;
            }

            if(arr[root]<arr[right])  //same as above
            {
                swap(arr[root],arr[right]);
                large=right;
            }

            if(large==root)  //this means that indeed the parent/root was greater than child and no swaps were made
                break;      //aka heap property is maintained
            else
                i=large;     //we follow the node we swapped and rinse and repeat
        }

        return root;
    }

    void print()
    {
        for(int i=0;i<current;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

int main()
{
    MaxHeap heap(5);
    heap.insert(2);
    heap.insert(4);
    heap.insert(1);
    heap.insert(5);
    heap.insert(6);

    cout<<heap.remove()<<endl<<endl;

    heap.print();
}
