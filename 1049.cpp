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
	int lastStoneWeightII(vector<int> &stones)
	{
		int sum = 0;
		for (auto n : stones) {
			sum += n;
		}
		vector<int> dp;
		dp.resize(sum / 2 + 1);

		for (int num : stones) {
			for (int i = sum / 2; i >= num; i--) {
				dp[i] = max(dp[i], dp[i - num] + num);
			}
		}
		return sum - 2 * dp[sum / 2];
	}
};

int main()
{
	vector<int> p{ 1, 1, 1, 1, 1 };
	Solution s;
	cout << s.lastStoneWeightII(p) << endl;
}
