/*    IMPLEMENTATION OF BUBBLE SORT

      Time Complexity :
            Best Case   : O(N)
            Worst Case  : O(N^2)
*/



#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int flag = 0;                //flag to detect any swap is there or not
        for(int j = 0; j < size-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                flag = 1;
            }
        }
        
        if(flag == 0)                  // if there will be NO swap in any pass, so array is sorted
            break;
    }
}

void swap(int &a , int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void display(int arr[] , int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of the array : ";
    cin >> size;
      
    int arr[size];
    
    cout << "\nEnter the elements in the array : " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    cout << "\nArray before Sorting : ";
    display(arr , size);
    
    bubbleSort(arr , size);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}



