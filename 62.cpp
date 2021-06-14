#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

class Solution {
    public:
	int uniquePaths(int m, int n)
	{
		if (m == 1 || n == 1)
			return 1;

		vector<int> dp;
		dp.resize(n);
		for (int i = 0; i < n; i++) {
			dp[i] = i + 1;
		}

		for (int y = 2; y < m; y++) {
			for (int x = 1; x < n; x++) {
				dp[x] += dp[x - 1];
			}
		}
		return dp[n - 1];
	}
};

int main()
{
	Solution s;
	cout << s.uniquePaths(3, 3) << endl;
}
