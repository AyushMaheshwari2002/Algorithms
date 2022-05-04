/*    IMPLEMENTATION OF MAX-HEAP SORT (Ascending Order)

      Time Complexity :
              Overall :	O(n logn)
              For creating and building heap : O(n)
*/


#include <iostream>
using namespace std;

void heapify(int arr[] , int size , int i)
{
    int largest = i;            // take largest element as root
    int l = (2 * i) + 1;        // left child
    int r = (2 * i) + 2;        // right child
    
    /* Basically in both the while loops, we have find the largest element b/w root's left child and root's right
       child so that we compare the largest value with root.
    */
    
    // If left child is larger than root
    while(l < size && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    while(r < size && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if(largest != i) 
    {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[] , int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        heapify(arr , size , i);             // i = Index of last non-leaf node
    }
    
    for(int i = size-1; i >= 0; i--)         // for deleting element in max heap
    {
        // move current root to the end of array
        swap(arr[0] , arr[i]);
        
        // this will check that after deleting the element, this satisfies the property of max heap or not.
        heapify(arr , i , 0);
    }
}


void swap(int &a , int &b)
{
    int temp = a;
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

    heapSort(arr , size);
    
    cout << "Array after Sorting : ";
    display(arr , size);
    
    return 0;
}


