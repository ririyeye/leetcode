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
	int findRadius(vector<int> &houses, vector<int> &heaters)
	{
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		int rad = 0;

		int index = 0;
		for (int hou : houses) {
			while (index < heaters.size() && heaters[index] < hou) {
				index++;
			}

			if (index == 0) {
				rad = max(rad, heaters[index] - hou);
			} else if (index == heaters.size()) {
				return max(rad, houses[houses.size() - 1] - heaters[heaters.size() - 1]);
			} else {
				rad = max(rad, min(heaters[index] - hou, hou - heaters[index - 1]));
			}
		}

		return rad;
	}
};

int main(int argc, char **argv)
{
	vector<int> houses = { 1, 2, 3 };
	vector<int> heaters = { 2 };
	Solution s;
	auto ret = s.findRadius(houses, heaters);
	return 0;
}
