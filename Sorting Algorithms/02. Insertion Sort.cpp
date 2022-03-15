/*    IMPLEMENTATION OF INSERTION SORT

      Time Complexity :
            Best Case   : O(N)
            Worst Case  : O(N^2)
*/



#include<iostream>
using namespace std;

void insertionSort(int arr[] , int size)
{
    int temp , j;
    for(int i = 1; i < size; i++)
    {
        temp = arr[i];
        j = i-1;
        
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
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
    
    insertionSort(arr , size);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}



