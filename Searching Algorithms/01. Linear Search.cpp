/* IMPLEMENTATION OF LINEAR SEARCH 

      Time Complexity :
              Best Case      : O(1)
              Average Case   : O(N)
              Worst Case     : O(N)

      Space Complexity : O(1)
*/



#include <iostream>
using namespace std;

void linearSearch(int arr[] , int size, int n)
{
    int flag = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == n)
        {
            cout << "Element found at index : " << i << endl;
            flag = 1;
            break;
        }
    }
    
    if(flag == 0)
        cout << "Element not Found!!!" << endl;
}

int main()
{
    int size;
    int arr[size];
    cout << "Enter size of the array : ";
    cin >> size;
    
    cout << "Enter the elements in the array : " << endl;
    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    
    int key;
    printf("\nEnter the element which you want to search : ");
    cin >> key;
    
    linearSearch(arr , size , key);
    
    return 0;
}


