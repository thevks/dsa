int dp[1001][1001];
int solve(vector<int> &val, vector<int>& wts, int w, int n)
{
	if (n == -1 or w == 0)
		return 0;

	if (dp[n][w] != -1) return dp[n][w];

	if (wts[n] > w ) 
	{
		return dp[n][w] = solve(val, wts, w, n-1);
	}

	int a = val[n] + solve(val, wts, wts[n]-w, n-1); 
	int b = solve(val, wts, w, n-1);
	
	return dp[n][w] = max(a,b);
}

int main(void)
{
	vector<int> val = {3,4,5,7,8};
	vector<int> wts = {2,4,1,4,7};

	int w = 30;
	int n = val.length();
	dp[n][w];
	memset(dp, -1, sizeof(dp));

	cout << solve(val, wts, w, n-1);

	return 0;
}
