#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	    
		  int LongestRepeatingSubsequence(string str){
		    int m, n = str.length();
		    int dp[2][n+1]; //Having only 2 rows
		    
		    for (int i=0;i<=m;i++)
		    {
		        for (int j=0;j<=n;j++)
		        {
		            if (i==0 or j == 0) 
		            {
		                dp[i][j] = 0;
		                continue;
		            }
		                
		            if (str[i-1] == str[j-1])
		                dp[i%2][j] = 1 + dp[(i+1)%2][j-1];
		            else {
		                dp[i%2][j] = max(dp[(i+1)%2][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[i%2][n];
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  
