#include <iostream>
#include <cstring>

using namespace std;
int dp[1000][1000];

int solve (string s, int i, int j)
{
	if (i > j)
		return 0;

	if (i == j)
		return 1;

	if (dp[i][j] != -1) return dp[i][j];

	if (s[i] == s[j])
		dp[i][j] = 1 + solve(s, i+1, j) + solve(s, i, j-1);
	else
		dp[i][j] = solve(s, i+1, j) + solve(s, i, j-1) - solve(s, i+1, j-1);

	return dp[i][j];
}

int main(void)
{
	string s = "abcd";
	int n = s.length();
	dp[n][n];
	memset(dp, -1, sizeof(dp));	

	cout << solve(s, 0, s.length() - 1);
}
