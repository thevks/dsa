#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int dp[1001][1001];
    
    long long int solve(int S[], int m, int n)
    {
        if (n == 0) return 1;
        
        if (n < 0 || m < 0) return 0;
        
        if (dp[m][n] != -1) return dp[m][n];
        
        dp[m][n] = solve(S, m, n-S[m]) + solve(S, m-1, n);
        
        return dp[m][n];
    }
    
    long long int count(int S[], int m, int n) 
    {
        dp[m][n+1];
        
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++)
                dp[i][j] = -1;
          
        return solve(S, m-1, n);
    }
};

int main() {

		/*
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }
		*/

		int n = 4, m = 3;
		int arr[] = {1, 2, 3};

		Solution ob;
    cout << ob.count(arr, m, n) << endl;

    return 0;
}  
