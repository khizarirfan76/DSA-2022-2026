//
// Created by khizar irfan on 10/10/2023.
//

#ifndef ARRAYLISTWITHPOINTER_ARRAYLIST_H
#define ARRAYLISTWITHPOINTER_ARRAYLIST_H
#include <iostream>
template<typename T>
class arrayList
{
public:
    T* ptr,arr;
    int filledSize,size;

    void next()
    {
        ptr++;
    }
    void start()
    {
        ptr=arr;
    }
    void previous()
    {
        ptr--;
    }
    void end()
    {
        ptr=arr+filledSize;         //pointer arithmetic
    }

    void addElement(T value,int index)
    {
        if(filledSize==-1)
        {
            *ptr=value;
        }
        else
        {
            end();
            for(int i=filledSize;i>=index;i--)
            {
                *(ptr+1)=*ptr;           //assuming agay khali space pari hui hai
                previous();
            }
            start();

            *(ptr+index)=value;
        }
        filledSize++;
    }

    void addElement(T a)
    {
        addElement(a,filledSize++);
    }

    void deleteElement(T value)
    {
        if(filledSize==-1)
            std::cout<<"error"<<std::endl;
        else{
            start();
            for (int i =0 ; i <=filledSize ; ++i) {
                if(*ptr==value)
                {
                    for (int j = i; j < filledSize; ++j) {
                        *ptr=*(ptr+1);
                        next();
                    }
                }
                filledSize--;

            }

        }

    }

    arrayList(int size)
    {
        arrayList::size=size;
        filledSize=-1;
    }

};


#endif //ARRAYLISTWITHPOINTER_ARRAYLIST_H
