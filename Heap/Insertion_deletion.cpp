#include <iostream>
using namespace std;

class Heap
{
public:

    // Declaring a Heap
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Function to Insert in a Max Heap
    void insert(int val)
    {   
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        // Check if inserted node is not at correct position
        while(idx > 1)
        {
            int parent = idx/2;
            if(arr[idx] > arr[parent])
            {
                swap( arr[idx] , arr[parent]);
                idx = parent;  
            } 
            else
            {
                return;
            }
        }
    }
    
    // Function to Print 
    void print()
    {
        for(int i = 1; i <= size; i++)
        {
            cout << arr[i] << " " << endl;
        }
        cout << endl;
    }

    // Function to delete
    void deletefromHeap()
    {
        // Check if the heap is empty
        if(size == 0){
            cout << "Heap is empty" <<endl;
            return;
        }

        // Delete root node by replacing with last node
        arr[1] = arr[size];
        size--;

        // Put the root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftidx = 2*i;
            int rightidx = 2*i+1;

            if(leftidx < size && arr[leftidx] > arr[i])
            {
                swap (arr[leftidx], arr[i]);
                i = leftidx;
            }
            else if(rightidx < size && arr[rightidx] < arr[i])
            {
                swap (arr[rightidx], arr[i]);
                i = rightidx;
            }
            else
            {
                return;
            }
        }
    }

};


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
    Heap h;
    
    cout << "Insert Heap Values" << endl;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletefromHeap();
    h.print();

    return 0;
}

