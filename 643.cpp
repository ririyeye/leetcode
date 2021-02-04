#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdint.h>
using namespace std;

class Solution {
    public:
	double findMaxAverage(vector<int> &nums, int k)
	{
		int maxsum = 0;
		int tmpsum = 0;
		for (size_t i = 0; i < k; i++) {
			tmpsum += nums[i];
		}

		maxsum = tmpsum;

		for (size_t i = 1; i < nums.size() - (k - 1); i++) {
			tmpsum = tmpsum - nums[i - 1] + nums[i + k - 1];
			if (tmpsum > maxsum) {
				maxsum = tmpsum;
			}
		}

		return (double)maxsum / (double)k;
	}
};
