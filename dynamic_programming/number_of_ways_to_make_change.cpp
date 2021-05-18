// A Dynamic Programming based C++ program to get ways count for a change
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_ways_for_change(vector<int> denoms, int target)
{
    vector<int> ways(target+1, 0);
    
    ways[0] = 1;

    for (int denom: denoms)
        for (int amount = 1; amount < target+1; amount++)
            if (denom <= amount)
                ways[amount] += ways[amount - denom];
    
    return ways[target];
}

int main(void)
{
    vector<int> denoms = {1, 5, 10, 25};
    int target = 10;
    cout << "Number of ways for change count for 10 : " << get_ways_for_change(denoms, target) << endl;
    return 0;
}