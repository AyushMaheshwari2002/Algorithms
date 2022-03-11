// IMPLEMENTATION OF BINARY SEARCH ON UNSORTED ARRAY (ITERATIVE APPROACH)

#include <bits/stdc++.h>
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
    
    // sort array using STL
    sort(arr , arr + size);
    
    /* Iterative method to sort an array
    int temp;
    for(int i = 0; i < size; i++)
    {
    	for(int j = i+1; j < size; j++)
	{
		if(arr[i] > arr[j])
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
    }*/
	
    //print sorted array elements
    cout<<"\nSorted (Ascending Order) Array elements : " << endl;
    for(int i = 0; i < size; i++)
    {
    	cout << arr[i] << "  ";
    }
    
    int key;
    cout << "\n\nEnter the element which you want to search : ";
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



// IMPLEMENTATION OF BINARY SEARCH ON UNSORTED ARRAY (RECURSIVE APPROACH)

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[] , int start , int end , int n)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;
        
        if(n == arr[mid])
        {
            return mid;
        }
        else if(n < arr[mid])
        {
            return binarySearch(arr , start , mid - 1 , n);            // move to left side 
        }
        else 
        {
            return binarySearch(arr , mid + 1 , end , n);        // move to right side
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
    
    // sort array using STL
    sort(arr , arr + size);
    
    /* Iterative method to sort an array
    int temp;
    for(int i = 0; i < size; i++)
    {		
    	for(int j = i+1; j < size; j++)
	{
		if(arr[i] > arr[j])
		{
          		temp = arr[i];
          		arr[i] = arr[j];
         	 	arr[j] = temp;
		}
	}
    }*/
	
    //print sorted array elements
    cout<<"\nSorted (Ascending Order) Array elements : " << endl;
    for(int i = 0; i < size; i++)
    { 
	cout << arr[i] << "  ";
    }
    
    int key;
    cout << "\n\nEnter the element which you want to search : ";
    cin >> key;
    
    int index = binarySearch(arr , 0 , size - 1 , key);
    
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



