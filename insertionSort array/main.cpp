#include <iostream>

using namespace std;

void InsertionSort(int* arr,int size)
{
    for (int i = 1; i < size; i++)
    {
        int j=i-1;
        int temp=arr[i];


        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;

    }
}

void PrintArray(int* arr,int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout<<arr[i]<<endl;

    }
}

int main()
{
   int arr[]={5,4,3,2,1};

    InsertionSort(arr,5);

    PrintArray(arr,5);

   

}
