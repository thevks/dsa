
int solve(int a[], int n, int dp[])
{
  if (n == -1) return 0;
  if (n == 0) return a[0];
  if (n == 1) return a[1] + a[0];
     
  if (dp[n] != -1) return dp[n];
  
  int a = a[n] + solve(a, n-2, dp);   //item is included
  int b = solve(a, n-1, dp);          //item is not included
  int c = a[n] + a[n-1] + solve(a, n-3, dp);
  
  dp[n] = max(a, max(b,c));
  
}

int main(void)
{
  int a[] = {};
  int n = sizeof(a)/sizeof(a[0]);
  
  int dp[n];
  memset(dp, -1, sizeof(dp));
  
  return solve(a, n-1, dp);
  
}
