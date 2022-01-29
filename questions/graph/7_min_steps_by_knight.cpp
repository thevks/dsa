nclude<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> v(N, vector<int>(N));
	    
	    for (int i=0;i<N;i++)
	        for (int j=0; j<N;j++)
	            v[i][j] = 0;
	   
	   int x1 = KnightPos[0];
	   int y1 = KnightPos[1];
	   
	   int x2 = TargetPos[0];
	   int y2 = TargetPos[1];
	   
	   //Initial position is the final position
	   if (x1 == x2 and x2 == y2) return 0;
	   
	   
	   queue<pair<int, int>> q;
	   q.push(make_pair(x1, y1));
	   
	   
	   while (!q.empty())
	   {
	       int i = q.front().first;
	       int j = q.front().second;
	       
	       q.pop();
	       
	       //Put all 8 conditions
	       if ((i-2) >=0 and (i-2) < N and (j-1) >=0 and (j-1) < N and (v[i-2][j-1] == 0)) {
	            v[i-2][j-1] = v[i][j] + 1;
	            q.push(make_pair(i-2, j-1));
	       }
	       
	       if ((i-2) >=0 and (i-2) < N and (j+1) >=0 and (j+1) < N and (v[i-2][j+1] == 0)) {
	            v[i-2][j+1] = v[i][j] + 1;
	            q.push(make_pair(i-2, j+1));
	       }
	       
	       if ((i+2) >=0 and (i+2) < N and (j-1) >=0 and (j-1) < N and (v[i+2][j-1] == 0)) {
	            v[i+2][j-1] = v[i][j] + 1;
	            q.push(make_pair(i+2, j-1));
	       }
	       
	       if ((i+2) >=0 and (i+2) < N and (j+1) >=0 and (j+1) < N and (v[i+2][j+1] == 0)) {
	            v[i+2][j+1] = v[i][j] + 1;
	            q.push(make_pair(i+2, j+1));
	       }
	   
	       if ((i-1) >=0 and (i-1) < N and (j-2) >=0 and (j-2) < N and (v[i-1][j-2] == 0)) {
	            v[i-1][j-2] = v[i][j] + 1;
	            q.push(make_pair(i-1, j-2));
	       }
	       if ((i-1) >=0 and (i-1) < N and (j+2) >=0 and (j+2) < N and (v[i-1][j+2] == 0)) {
	            v[i-1][j+2] = v[i][j] + 1;
	            q.push(make_pair(i-1, j+2));
	       }
	       
	       if ((i+1) >=0 and (i+1) < N and (j-2) >=0 and (j-2) < N and (v[i+1][j-2] == 0)) {
	            v[i+1][j-2] = v[i][j] + 1;
	            q.push(make_pair(i+1, j-2));
	       }
	       if ((i+1) >=0 and (i+1) < N and (j+2) >=0 and (j+2) < N and (v[i+1][j+2] == 0)) {
	            v[i+1][j+2] = v[i][j] + 1;
	            q.push(make_pair(i+1, j+2));
	       }
	       
	   }
	   
	   return v[x2][y2];
	   
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
