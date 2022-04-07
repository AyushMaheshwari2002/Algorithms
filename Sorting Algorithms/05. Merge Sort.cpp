/*    IMPLEMENTATION OF MERGE SORT
      
      Time Complexity :
            Best Case / Average Case / Worst Case : O(n logn)
            
      Space Complexity : O(n)
*/



#include <iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int temp[ub - lb + 1];               // take extra array for joining different parts of original array
    
    // Merge two different parts into temp array
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    
    if(i > mid)
    {
        // Insert all the remaining elements from j(mid + 1) to ub into temp array
        while(j <= ub)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        // Insert all the remaining elements from i(lb) to mid into temp array
        while(i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    
    // Assign sorted data stored in temp[] to arr[].
    for(k = lb; k <= ub; k++)
    {
        arr[k] = temp[k];
    }
}

void mergeSort(int arr[], int lb, int ub)
{
    if(lb < ub)
    { 
        int mid = (lb + ub) / 2;
        
        // split or divide the array into two parts 
        mergeSort(arr , lb , mid);
        mergeSort(arr , mid+1 , ub);
        
        // merge the array to get sorted output
        merge(arr , lb , mid , ub);
        
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
    
    mergeSort(arr , 0 , size-1);
    
    cout << "Array after Sorting : ";
    display(arr , size);
}


