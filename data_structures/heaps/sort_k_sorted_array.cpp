#include <iostream>
//#include "min_heap.h"
using namespace std;

int main(void)
{
    int a[] = {3, 2, 1, 5, 4, 7, 6, 5};
    int k = 3; //3 sorted array
    int n = sizeof(a)/sizeof(a[0]);
    int i;
    min_heap *h = min_heap());
    
    //Build a min heap of initial k elements of the array
    for (i=0; i<k; i++)
        h.insert(a[i]);
    
    //Iterate array positions to fill the min element from the heap
    for (i=0; i<n; i++)
    {
        if (i+k < n)
            h.insert(a[i+k]);
        a[i] = h.get_min();
        h.delete_min();
    }
 
    cout << "Sorted array: "
    for (int j : a)
        cout<< a[j] << " ";

    return 0;
}