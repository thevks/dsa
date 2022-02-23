#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int dp[1001][1001];
    
    int solve(int x, int y, string s1, string s2)
    {
        if (x < 0 or y < 0) 
            return 0;
        
        if (dp[x][y] != -1) 
            return dp[x][y];
        
        if (s1[x] == s2[y]) 
            return dp[x][y] = 1 + solve(x-1, y-1, s1, s2);
        else {
            int a = solve(x-1, y, s1, s2);
            int b = solve(x, y-1, s1, s2);
            
            return dp[x][y] = max(a, b);
        }
        
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        dp[x][y];
        for (int i=0; i<x; i++)
            for (int j=0; j<y; j++)
                dp[i][j] = -1;
        
        return solve(x-1, y-1, s1, s2);
        
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
