#include <string>
#include <iostream>
using namespace std;

int dp[1001][1001];


//Not sure - how DP is helping here as value of i & j is changing in every instance of invocation
//So history is not required
int solve(string x, string y, string z, int i, int j, int k)
{
	if (k == -1)
		return 1;

	if (dp[i][j] != -1) return dp[i][j];

	int a, b;

	if (i>=1 and z[k] == x[i]) a = solve(x,y,z,i-1,j,k-1);
	if (j>=1 and z[k] == y[j]) b = solve(x,y,z,i,j-1,k-1);		 

	return dp[i][j] = a | b;
}

int is_interleaving_recursive(string x, string y, string z)
{
	if (x.length() + y.length() != z.length())
		return 0;

	return solve(x, y, z, x.length()-1, y.length()-1, z.length()-1);	
}

//TC - O(x.length + y.length)
//SC - O(1)
int is_interleaving_iterative(string x, string y, string z)
{
	if (x.length() + y.length() != z.length())
		return 0;

	int n = z.length();
	int i=0, j=0, k;

	for (k=0;k<n;k++)
	{
		if(z[k] == x[i]) i++;
		else if (z[k] == y[j]) j++;
		else break;				
	}
	
	if (k != n)
		return 0;

	return 1;
}

int main(void)
{
	string x="abc";
	string y="def";

	string z="adebcf"; 
	
	dp[x.length()][y.length()];
	memset(dp, -1, sizeof(dp));

	cout << is_interleaving_recursive(x, y, z) << endl;
	cout << is_interleaving_iterative(x, y, z) << endl;
}
