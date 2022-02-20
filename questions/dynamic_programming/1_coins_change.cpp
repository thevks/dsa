// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dp[1001][1001];
    
    int solve(int W, int wt[], int val[], int n)
    {
        if (W == 0 or n < 0) return 0;
        
        if (dp[n][W] == -1) return dp[n][W];
        
        //Skip if weight to be considered is more than the expected
        if (wt[n] > W)
            return dp[n][W] = solve(W, wt, val, n-1);
        
        int include = val[n] + solve(W-wt[n], wt, val, n-1);
        int exclude = solve(W, wt, val, n-1);
        
        dp[n][W] = max(include, exclude);
        
        return dp[n][W];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        for (int i=0; i<n; i++)
            for (int j=0; j<W; j++)
                dp[i][j] = -1;
            
        return solve(W, wt, val, n-1);    
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
