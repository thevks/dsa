long long int dp[1000][1000];
    
long long int solve(int s[], int m, int n)
{
        if (m==-1 and n>0)
            return 0;
        
        if (n==0)
            return 1;
        
        if (n<0)
            return 0;
    
        if (dp[m][n] != -1) return dp[m][n];
        
        dp[m][n] = solve(s, m, n-s[m]) + solve(s, m-1, n);
        
        return dp[m][n];
}
    
long long int count(int S[], int m, int n) {
        dp[m][n];
        memset(dp, -1, sizeof(dp));
        return solve(S, m-1, n);
        
}
