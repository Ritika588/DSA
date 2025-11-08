#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
     
    priority_queue <int> maxHeap;
    priority_queue < int, vector<int>, greater<int>> minHeap;

    MedianFinder() {}
      
    void addNum(int num)
    {   
        // if Maxheap is empty
        if(maxHeap.size() == 0)
        {
            maxHeap.push(num);
            return;
        }

        // if smaller element added (0) in 1 2 3 
        if(num < maxHeap.top())
        {
            maxHeap.push(num);
            if(maxHeap.size() - minHeap.size() > 1)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }

        else
        {
            // if element is larger 
            minHeap.push(num);
            if(minHeap.size() - maxHeap.size() > 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

        }
    }
    
    
    double findMedian() {

        if(minHeap.size() == maxHeap.size())
        {
            int a = minHeap.top();
            int b = maxHeap.top();
            return (a + b)/2.0;
        }
        else if (maxHeap.size() > minHeap.size())
        {
            return maxHeap.top();
        }
        else
        {
            return minHeap.top();
        }
    }

};



int main()
{
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(6);
    cout << "Median is: " << mf.findMedian() << endl;

    mf.addNum(7);
    cout << "Median is: " << mf.findMedian() << endl;

    mf.addNum(0);
    cout << "Median is: " << mf.findMedian() << endl;

    mf.addNum(4);
    cout << "Median is: " << mf.findMedian() << endl;

    mf.addNum(3);
    cout << "Median is: " << mf.findMedian() << endl;


    return 0;
}


