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
	int numSquares(int n)
	{
		int num = sqrt(n);
		vector<int> dp(n + 1, 10000);
		dp[0] = 0;

		for (int i = 1; i <= num; i++) {
			for (int j = i * i; j <= n; j++) {
				dp[j] = min(dp[j], dp[j - i * i] + 1);
			}
		}
		return dp[n];
	}
};

int main()
{
	Solution s;
	cout << s.numSquares(12) << endl;
}
