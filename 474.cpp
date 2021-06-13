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
	int findMaxForm(vector<string> &strs, int m, int n)
	{
		vector<int> dp;
		dp.resize((m + 1) * (n + 1));
		// int *dp = new int[(m + 1) * (n + 1)];

		for (auto str : strs) {
			int zeros = 0;
			int ones = 0;

			for (auto chr : str) {
				if (chr == '0') {
					zeros++;
				} else {
					ones++;
				}
			}

			for (int x = m; x >= zeros; x--) {
				for (int y = n; y >= ones; y--) {
					dp[x * (n + 1) + y] = max(dp[x * (n + 1) + y], 1 + dp[(x - zeros) * (n + 1) + (y - ones)]);
				}
			}
		}
		return dp[m * (n + 1) + n];
	}
};

int main()
{
	vector<string> strs = { "10","0001","111001","1","0" };
	Solution s;
	cout << s.findMaxForm(strs, 5, 3) << endl;
}
