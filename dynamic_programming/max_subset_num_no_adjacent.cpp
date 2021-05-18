#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> array = {7, 10, 12, 7, 9, 14};
    vector<int> max_sums(array.size());

    max_sums[0] = array[0];
    max_sums[1] = array[1];

    for(int i=2; i<array.size(); i++)
        max_sums[i] = max (max_sums[i-1], max_sums[i-2] + array[i]);

    cout << "Max sum array: " << endl;
    for(int a: max_sums)
        cout << a << " ";
    
    cout << endl;
    
    return 0;    
} 
