int dp[1001];

int solve(int a[], int n)
{
	if(n < 0) return 0; 
	
	if (dp[n] != -1) return dp[n];

	int x = a[n] + solve(a, n-2);
	int y = solve(a, n-1);

	return dp[n] = max(x,y);
}


int main(void)
{
	int a[] = {};
	int n = sizeof(a)/sizeof(a[0]);
	dp[n];
	memset(dp, -1, sizeof(dp));

	cout << solve(a, n-1);
}
