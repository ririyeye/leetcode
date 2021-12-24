
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>
#include <stdint.h>

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
	struct pair {
		pair(int enday, int nums)
			: end_days(enday), nums(nums)
		{
		}
		int end_days;
		int nums;
		friend bool operator<(const pair &A, const pair &B)
		{
			return A.end_days > B.end_days;
		}
	};

	int eatenApples(vector<int> &apples, vector<int> &days)
	{
		priority_queue<pair> q;
		int eat = 0;

		int len = apples.size();
#if 0
		for (int i = 0; i < len; i++) {
			if (apples[i] != 0) {
				q.emplace(i + days[i], apples[i]);
			}
		}
#endif
		for (int daynum = 0; !q.empty() || (daynum < len); daynum++) {
			//eat one
			if (!q.empty()) {
				pair &pr = (pair &)q.top();
				if (--pr.nums == 0) {
					q.pop();
				}
				eat++;

				//clean out date
				while (!q.empty()) {
					if (q.top().end_days == daynum) {
						q.pop();
					} else {
						break;
					}
				}
			}

			if (daynum < len && apples[daynum] != 0) {
				q.emplace(daynum + days[daynum], apples[daynum]);
			}
		}

		return eat;
	}
};

int main(int argc, char **argv)
{
	vector<int> apples = { 1, 2, 3, 5, 2 };
	vector<int> days = { 3, 2, 1, 4, 2 };
	Solution s;
	auto ret = s.eatenApples(apples, days);
	return 0;
}
