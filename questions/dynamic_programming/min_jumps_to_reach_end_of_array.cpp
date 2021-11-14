#include <iostream>
using namespace std;

int main(void)
{
	int a[] = {1, 4, 3, 2, 6, 7};
	int n = sizeof(a)/a[0];

	int dp[n];
	memset(dp, INT_MAX, sizeof(dp));
	dp[0] = 0;

	for (i=1;i<n;i++)
	{
		for (j=0;j<i;j++)
		{
			if ((dp[j] != INT_MAX) and (a[j] + j >= i))
			{
				if (dp[j] + 1 < dp[i])
					dp[i] = min(dp[i], dp[j] + 1);
			}
		}
	}

	if (dp[n-1] != INT_MAX) return dp[n-1];
	else return -1;
	

	return 0;
}
