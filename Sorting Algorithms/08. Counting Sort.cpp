/*    IMPLEMENTATION OF COUNTING SORT
      
      Time Complexity :
            Best Case / Average Case / Worst Case : O(n + k) 
            where,
                    n = number of elements in input array
                    k = range of input (max element)
            
      Space Complexity : O(n + k)
      
      Stable : Yes
*/


#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[] , int size)
{
    // find maximum element
    int max = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        max = arr[i];
    }
    
    int output[size];
    int count[max + 1];
    
    // Initialize count array with all zeros.
    for(int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    
    // count the frequency of each element and store it into count array
    for(int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    
    // Store the cummulative count of each array
    for(int i = 1; i <= max; i++) 
    {
        count[i] += count[i - 1];
    }
    
    // for sorting and placing element into right address
    for(int i = size-1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    
    // Copy the sorted elements into original array
    for(int i = 0; i < size; i++) 
    {
        arr[i] = output[i];
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
    
    countingSort(arr , size);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}



