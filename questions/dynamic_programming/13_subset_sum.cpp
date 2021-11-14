int dp[1001][1001];

int solve(int a[], int s, int n)
{
	if (n == -1)
	{
		if (s == 0)
			return 1;
		else
			return 0;
	}

	if (s<0) return 0;

	if (s == 0) return 1;

	if (dp[n][s] != -1) return dp[n][s];

	return dp[n][s] = solve(a, s-a[n], n-1) || solve(a, s, n-1); 
}

int main(void)
{
	int a[] = { };
	int n = sizeof(a)/sizeof(a[0]);
	int s = 0;
	for (int i=0;i<n;i++) 
		s += a[i];

	if (s & 1)
		return 0;

	s = s/2;

	dp[n][s];
	memset(dp, -1, sizeof(dp));

	cout << solve(a, s, n-1);

}
