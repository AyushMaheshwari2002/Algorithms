/*    IMPLEMENTATION OF QUICK SORT
      
      Time Complexity :
            Best Case / Average Case  : O(n logn)
            Worst Case  : O(N^2)
*/



#include <iostream>
using namespace std;

int partition(int arr[], int lb, int ub)
{
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    
    while(start < end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(arr[start] , arr[end]);
        }
    }
    swap(arr[lb] , arr[end]);
    
    return end;
}

void swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    { 
    	// partitioning the array
    	int p = partition(arr, lb , ub);
    
    	// Sorting the left part
    	quickSort(arr, lb , p - 1);
    
    	// Sorting the right part
    	quickSort(arr, p + 1 , ub);
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
    
    quickSort(arr , 0 , size-1);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}


