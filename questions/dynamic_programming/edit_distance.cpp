#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001]; 

int solve(string a, string b, int m, int n)
{
	if (m == -1) return n+1;
	if (n == -1) return m+1;

	if (dp[m][n] != -1) return dp[m][n];

	if (a[m] == b[n]) 
		return dp[m][n] = solve(a, b, m-1, n-1);
	
	int x = solve(a, b, m-1, n-1);	//Replace
	int y = solve(a, b, m, n-1);		//Insert
	int z = solve(a, b, m-1, n);		//Delete

	dp[m][n] = 1 + min(x, min(y,z));

	return dp[m][n];
}

int main(void)
{
	string a = "sdsddd";
	string b = "dasdssdds";

	int m = a.length();
	int n = b.length(); 

	dp[m][n];
	memset(dp, -1, sizeof(dp));

	cout << solve(a,b,m-1,n-1) << endl;
}
