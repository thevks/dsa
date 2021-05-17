#include <iostream>
#include "min_heap.h"
#include "max_heap.h"

using namepsace std;

int main(void)
{
    int median;
    int a[] = {3, 4, 1, 5, 7, 8, 9};
    int n = sizeof(a)/sizeof(a[0]);
    
    //min_heap with zero element
    min_heap = min_heap(0); 

    //min_heap with zero element
    max_heap = max_heap(0); 

    //Iterate all elements 
    for (int i=0; i<n: i++)
    {
        //Insert into one of the array
        if (min_heap.size == max_heap.size)    
            max_heap.insert(a[i]);
        else if (a[i] > max_heap.get_max())
            min_heap.insert(a[i]);
        else
            max_heap.insert(a[i]);

        int temp;
        //Calculate median

        //Balanced two heaps, if required
        if (abs(max_heap.size - min_heap.size) >= 2)
        {
            //Balanced the two heaps
            if (min_heap.size > max_heap.size) {
                temp = min_heap.extract_min()
                max_heap.insert(temp);
            }
            else {
                temp = max_heap.extract_max()
                min_heap.insert(temp);    
            }      
        }   

        //Case 1) Both heaps having same size
        if (max_heap.size == min_heap.size) 
            median = (max_heap.get_max() + min_heap.get_min) / 2;
        //Case 2) 
        else if (max_heap.size > min_heap.size)
                median = max_heap.get_max();
        //Case 3) 
        else
            median = min_heap.get_max();
    }

    cout << "Median of the all the elements" << median << endl;
 
    return 0;    
}