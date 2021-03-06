
#include <iostream>
#include <vector>

using namespace std;
int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity,
                        int currentIndex) 
{

    if (capacity <= 0 || currentIndex >= profits.size()) {
      return 0;
    }

    // recursive call after choosing the element at the currentIndex
    // if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
    int profit1 = 0;
    if (weights[currentIndex] <= capacity) {
      profit1 =
          profits[currentIndex] +
          knapsackRecursive(profits, weights, capacity - weights[currentIndex], currentIndex + 1);
    }

    // recursive call after excluding the element at the currentIndex
    int profit2 = knapsackRecursive(profits, weights, capacity, currentIndex + 1);

    return max(profit1, profit2);
}


int main(int argc, char *argv[]) 
{
 
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
 
  int maxProfit = knapsackRecursive(profits, weights, 7, 0);
  cout << "Total knapsack profit:  " << maxProfit << endl;
 
  maxProfit = knapsackRecursive(profits, weights, 6, 0);
  cout << "Total knapsack profit:  " << maxProfit << endl;

  return 0;
}