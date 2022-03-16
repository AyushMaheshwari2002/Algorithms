/*    IMPLEMENTATION OF SELECTION SORT

      Time Complexity :
            Best Case   : O(N^2)
            Worst Case  : O(N^2)
*/



#include<iostream>
using namespace std;

void selectionSort(int arr[] , int size)
{
    int i , j;
    for(i = 0; i < size-1; i++)
    {
        int min = i;
        for(j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        
        if(min != i)
        {
            swap(arr[i] , arr[min]);
        }
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
    
    selectionSort(arr , size);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}



