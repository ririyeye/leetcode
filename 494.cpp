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
	int findTargetSumWays(vector<int> &nums, int target)
	{
		int sum = 0;
		for (auto n : nums) {
			sum += n;
		}

		sum += target;

		if (sum % 2 != 0) {
			return 0;
		}

		sum /= 2;

		vector<int> dp;
		dp.resize(sum + 1);
		dp[0] = 1;

		for (int num : nums) {
			for (int i = sum; i >= num; i--) {
				dp[i] += dp[i - num];
			}
		}
		return dp[sum];
	}
};

int main() {
    vector<int> p {1,1,1,1,1};
    Solution s;
    cout << s.findTargetSumWays(p,3) << endl;

}
