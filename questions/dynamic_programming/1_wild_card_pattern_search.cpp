#include <iostream>
#include <cstring>

using namespace std;
int dp[1000][1000];

int solve(string t, string p, int m, int n)
{

	if (m == -1 and n == -1)
		return 1;

	if (m == -1) {
		for (int i=0;i<n;i++)
			if (p[i] != '*')
				return 0;
		return 1;
	}

	if (n == -1)
		return 0;
		
	if (dp[m][n] != -1) return dp[m][n];

	if (t[m] == p[n] || p[n] == '?')
		return dp[m][n] = solve(t, p, m-1, n-1);
	else if (p[n] == '*')
		return dp[m][n] == solve(t, p, m, n-1) or solve(t, p, m-1, n);

	return dp[m][n] = 0;
}

int main(void)
{
	string t = "abcba";
	string p = "a?c*a";

	int m = t.length();
	int n = p.length();
	memset(dp, -1, sizeof(dp));
	
	cout << solve(t, p, m-1, n-1);
	return 0;
}
