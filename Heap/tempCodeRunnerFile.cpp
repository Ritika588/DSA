#include<iostream>
using namespace std;


void print(int arr[], int n)
{
    for(int i = 1; i <= n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// Heapify algorithm
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    // Check if the node is at its correct position 
    if( left < n && arr[largest] < arr[left])
        largest = left;
    
    if(right < n && arr[largest] < arr[right])
        largest = right;

    // if its not then swap it and check recursively 
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: "<< endl;
    cin >> n;
    
    int arr[n + 1];
    arr[0] = -1;

    cout << "Enter array elements: " << endl;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for(int i = n/2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    print(arr, n);

    return 0;
}