#include <iostream>
using namespace std;

//T:O(N), S:O(1)
int solve()
{

	int a[] = {3, 0, 0, 2, 0, 4};
	int n = sizeof(a)/sizeof(a[0]);

	int max_left = 0, max_right = 0;

	int l = 0, r = n -1;

	int ans = 0;

	while (l <=r )
	{
		if (a[l] < a[r]) {
			if (a[l] > max_left) max_left = a[l];
			else ans += max_left - a[l];
			
			l++;
		}
		else {
			if (a[r]	> max_right) max_right = a[r];
			else ans += max_right - a[r];	

			r--;
		} 
	}

	return ans;
}

int main(void)
{
	cout << solve() << endl;
}

