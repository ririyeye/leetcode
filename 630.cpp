#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

#include <queue>

using namespace std;

class Solution {
    public:
	int scheduleCourse(vector<vector<int> > &courses)
	{
		sort(courses.begin(), courses.end(), [](const auto &c0, const auto &c1) {
			return c0[1] < c1[1];
		});

		priority_queue<int> q;

		int total = 0;

		for (const auto &couse : courses) {
			int day = couse[0];
			int end = couse[1];

			if (total + day <= end) {
				total += day;
				q.push(day);
			} else if (q.size() && q.top() > day) {
				total = total - (q.top() - day);
				q.pop();
				q.push(day);
			}
		}

		return q.size();
	}
};

int main(int argc, char **argv)
{
	vector<vector<int> > test = {
		{ 100, 200 },
		{ 200, 1300 },
		{ 1000, 1250 },
		{ 2000, 3200 },
	};
	Solution s;
	auto ret = s.scheduleCourse(test);
	return 0;
}
