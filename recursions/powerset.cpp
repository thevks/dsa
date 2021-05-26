#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> helper(vector<int>& a, int idx)
{
    if (idx < 0)
        return vector<vector<int>>{{}};
    
    int element = a[idx];
    vector<vector<int>> subsets = helper(a, idx-1);
    int length = subsets.size();

    for (int i=0; i<length;i++)
    {
        vector<int> new_set = subsets[i];
        new_set.push_back(element);
        subsets.push_back(new_set);    
    }
    return subsets;
}

vector <vector<int>> powerset(vector<int>& a)
{
    return helper(a, a.size() - 1);   
}

int main(void)
{
    vector<int> a = {1,2,3};

    vector <vector<int>> subsets = powerset(a);
 
    int length = subsets.size();

    for (int i=0; i<length; i++)
    {
        vector<int> s = vector<int>(subsets[i]);
        cout << "[";
        for (int e: s)
           cout<< e <<"";
        cout << "]";
        cout << endl;
    }

    return 0;
}