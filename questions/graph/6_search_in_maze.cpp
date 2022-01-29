#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
    public:
    
    void dfs(int i, int j, vector<vector<int>> &m, int n, vector<string> ans, string s, vector<vector<int>> &visited)
    {
        if (i<0 or j<0 or i>=n or j>=n) return;
        
        if ((m[i][j] == 0) or (visited[i][j] == 1)) return;
        
        if (i==n-1 and j==n-1) {
            ans.push_back(s);
            return;
        }
        
        visited[i][j] = 1;
        
        dfs(i, j-1, m, n, ans, s + 'L', visited);
        dfs(i, j+1, m, n, ans, s + 'R', visited);
        dfs(i-1, j, m, n, ans, s + 'U', visited);
        dfs(i+1, j, m, n, ans, s + 'D', visited);
        
        visited[i][j] = 0;
    
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        ans.clear();
        
        if ((m[0][0] == 0) or (m[n-1][n-1] == 0))
            return ans;
        
        vector<vector<int>> visited(n, vector<int>(n));
        
        string s="";
        dfs(0,0,m,n,ans,s, visited);
        
        return ans;
        
    }
};

int main() {
	int n = 4;
	vector<vector<int>> m = {
													 {1, 0, 0, 0},
													 {1, 1, 0, 1},
													 {1, 1, 0, 0},
													 {0, 1, 1, 1}
												};

  Solution obj;
  vector<string> result = obj.findPath(m, n);
  sort(result.begin(), result.end());
  if (result.size() == 0)
  	cout << -1;
  else
  	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
  return 0;

}  
