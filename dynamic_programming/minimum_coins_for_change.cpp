// A Dynamic Programming based C++ program to find minimum of coins
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_min_coins_change_count(vector<int> denoms, int target)
{
    vector<int> nums(target+1, INT_MAX);
    int amount;

    nums[0] = 0;

    for (int denom: denoms)
        for (amount = 1; amount < target+1; amount++)
            if (denom <= amount)
                nums[amount] = min(nums[amount], 1 + nums[amount - denom]);
    
    if (nums[target] != INT_MAX)
        return nums[target];
    else
        return -1;
}

int main(void)
{
    vector<int> denoms = {1, 2, 4};
    int target = 6;
    cout << "Min coins change count is : " << get_min_coins_change_count(denoms, target) << endl;
    return 0;
}