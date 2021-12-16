#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>

using namespace std;

class Solution {
    public:
	int visiblePoints(vector<vector<int> > &points, int angle, vector<int> &location)
	{
		vector<float> dg;

		int overlay = 0;
		for (auto &point : points) {
			if (point[0] == location[0]) {
				if (point[1] > location[1]) {
					dg.emplace_back(90.0f);
				} else if (point[1] < location[1]) {
					dg.emplace_back(-90.0f);
				} else {
					overlay++;
				}
			} else if (point[1] == location[1]) {
				if (point[0] > location[0]) {
					dg.emplace_back(0);
				} else if (point[0] < location[0]) {
					dg.emplace_back(180.0f);
				} else {
					overlay++;
				}
			} else {
				dg.emplace_back(atan2(point[1] - location[1], point[0] - location[0]) * 180 / M_PI);
			}
		}

		sort(dg.begin(), dg.end());

		int sz = dg.size();
		for (int i = 0; i < sz; i++) {
			if (dg[i] < angle - 180) {
				dg.emplace_back(dg[i] + 360);
			} else {
				break;
			}
		}
		int max_cnt = 0;

        int right = 1;
		for (int left = 0; left < sz; left++) {
			while (right < dg.size() && dg[right] <= dg[left] + angle) {
				right++;
			}
			max_cnt = max(max_cnt, right - left);
		}
		return max_cnt + overlay;
	}
};

int main(int argc, char **argv)
{	
	vector<vector<int> > test = {
{51,20},{90,47},{12,70},{66,29},{96,49},{49,28},{71,96},{13,50},{79,4},{45,97},{30,35},{75,79},{85,24},{77,42},{52,7},{64,8},{89,2},{40,79},{11,11},{24,32},{7,46},{26,47},{85,97},{33,2},{81,68},{5,51},{94,9},{10,6},{88,85},{5,72},{32,12},{14,39},{65,37},{18,34},{98,33},{52,66},{77,76},{83,72},{36,94},{65,19},{28,79},{36,53},{23,21},{47,43},{65,53}

	};
	int angle = 32;
	vector<int> location = { 33,55 };
	Solution s;
	auto ret = s.visiblePoints(test, angle, location);
	return 0;
}
