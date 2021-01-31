#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
    public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int m = nums1.size();
		int n = nums2.size();
		int left = (m + n + 1) / 2;
		int right = (m + n + 2) / 2;

		if (left == right)
			return findKth(nums1, 0, nums2, 0, left);
		else
			return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
	}
	//i: nums1的起始位置 j: nums2的起始位置
	int findKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
	{
		if (i >= nums1.size())
			return nums2[j + k - 1]; //nums1为空数组
		if (j >= nums2.size())
			return nums1[i + k - 1]; //nums2为空数组
		if (k == 1) {
			return min(nums1[i], nums2[j]);
		}
		int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : 0x7fffffff;
		int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : 0x7fffffff;
		if (midVal1 < midVal2) {
			return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
		} else {
			return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
		}
	}
};

int main(int argc, char **argv)
{
	vector<int> a({1});
	vector<int> b({2,3,4,5,6});

	Solution s;
	auto ret = s.findMedianSortedArrays(a, b);
	printf("%f\n", ret);
}
