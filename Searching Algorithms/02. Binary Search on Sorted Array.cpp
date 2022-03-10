/* IMPLEMENTATION OF BINARY SEARCH ON SORTED ARRAY (ITERATIVE APPROACH)

      Time Complexity :
              Best Case      : O(1)
              Average Case   : O(log N)
              Worst Case     : O(log N)

      Space Complexity : O(1)
*/



#include <iostream>
using namespace std;

int binarySearch(int arr[] , int size, int n)
{
    int start = 0, end = size - 1;
    while(start <= end)
    {
        int mid = (start + end) / 2;
        
        if(n == arr[mid])
        {
            return mid;
        }
        else if(n < arr[mid])
        {
            end = mid - 1;            // move to left side 
        }
        else 
        {
            start = mid + 1;        // move to right side
        }
    }
    return -1;
}

int main()
{
    int size;
    
    cout << "Enter size of the array : ";
    cin >> size;
    
    int arr[size];
    
    cout << "Enter the elements in the array : " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    cout << "\nEnter the element which you want to search : ";
    cin >> key;
    
    int index = binarySearch(arr , size , key);
    
    if(index != -1)
    {
        cout << "Element is found at index : " << index << endl;
    }
    else 
    {
        cout << "Element not Found!!!" << endl;
    }
    
    return 0;
}



