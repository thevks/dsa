#include <iostream>
using namespace std;

int edit_distance(string str1, string str2, int m, int n)
{
	int distance[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				distance[i][j] = j; 
			else if (j == 0)
				distance[i][j] = i; 
			else if (str1[i - 1] == str2[j - 1])
				distance[i][j] = distance[i - 1][j - 1];
			else
				distance[i][j] = 1 + min(distance[i][j-1],
							      min(distance[i-1][j], 
							      distance[i-1][j-1])); 
		}
	}

	return distance[m][n];
}

int main()
{

	string str1 = "abc";
	string str2 = "yabd";

	cout << edit_distance(str1, str2, str1.length(), str2.length()) << endl;

	return 0;
}
