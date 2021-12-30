#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>

using namespace std;
class Solution {
    public:
	bool isNStraightHand(vector<int> &hand, int groupSize)
	{
		int len = hand.size();
		if (len % groupSize != 0) {
			return false;
		}

		map<int, int> um;

		for (auto &card : hand) {
			um[card]++;
		}

		while (!um.empty()) {
			auto itr = um.begin();

			int base_num = itr->first;
			if (--itr->second == 0) {
				um.erase(itr);
			}

			for (int i = 1; i < groupSize; i++) {
				auto find_itr = um.find(base_num + i);
				if (find_itr == um.end()) {
					return false;
				} else {
					if (--find_itr->second == 0) {
						um.erase(find_itr);
					}
				}
			}
		}
		return true;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> ppp{ 1, 2, 3, 6, 2, 3, 4, 7, 8 };
	auto ret = s.isNStraightHand(ppp, 3);
	// printf("%s\n", ret.c_str());
}
