//Muhammad Khizar Irfan                   0248-BSCS-22
#include <iostream>
using namespace std;

template<typename T>

struct arrayList
{
    T* arr=nullptr;       //T is used because we have to tell to what datatype the pointer points to
    int usedSpace=0;       //it keeps track of how many elemnts are added helpful when traversing the array
    int capacity=10;       //it keeps track of the max size of the arrayList only used in grow() for simplicity


    void grow()        //grows capacity by one
    {
        capacity++;
        T* temp=new T[capacity];

        for(int i=0;i<usedSpace;i++)
        {
            temp[i]=arr[i];
        }

        arr=temp;
        delete[](temp);
    }

    void add(T element)       //adds element at the end of arraylist
    {
        if(arr==nullptr || usedSpace>=capacity)
        {
            grow();
            arr[usedSpace]=element;

        }
        else
            arr[usedSpace]=element;
        usedSpace++;
    }
    void insert(T element,int index)
    {
        if(index>=capacity || index<0)
            cout<<"out of bounds"<<endl;
        else
        {                            //capacity = usedSpace(such that 5=5) the max index availble will be 4
            if (usedSpace>=capacity)     //we have to use "=" too because arrays start from zero and even if
                grow();
            for(int i=usedSpace;i>index;i--)      //moves all elements one the right side further right by one
            {                                   //hint: if you want elemnts to move to right use i--
                arr[i]=arr[i-1];
            }
            arr[index]=element;
            usedSpace++;          //updates usedSpace
        }

    }

    void remove(int index)
    {
        if (arr==nullptr)
            cout<<"list is empty"<<endl;
        else
        {
            for (int i = index; i < usedSpace; i++)          //moves elemnents after the index to the left hence
            {                                           //the deleted elemnt is overwrited
                arr[i]=arr[i+1];
            }
            usedSpace--;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, arrayList& list) {
        os << "[";
        for (int i = 0; i < list.usedSpace; i++) {
            os << list.arr[i];
            if (i < list.usedSpace - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
    arrayList()
    {
        arr=new T[capacity];
    }
    arrayList(int capacity)
    {
        this->capacity=capacity;
        arr=new int[capacity];
    }
    ~arrayList()
    {
        delete[] arr;
    }

};
int main()
{
    arrayList<char> list;
    list.add('a');
    list.add('c');
    list.add('f');
    list.add('a');

    cout<<list<<endl;

    list.insert('a',3);

    cout<<list<<endl;

    list.remove(2);
    cout<<list<<endl;

}