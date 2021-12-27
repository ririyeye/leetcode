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
	int numFriendRequests(vector<int> &ages)
	{
		unordered_map<int, int> mp;
		for (auto age : ages) {
			mp[age]++;
		}

		int connect = 0;

		auto connectfun = [](int x, int y) {
			if (y <= (x + 14) / 2) {
				return 0;
			}
			if (y > x) {
				return 0;
			}
			if (y > 100 && x < 100) {
				return 0;
			}
			return 1;
		};

		for (auto itrX = mp.begin(); itrX != mp.end(); ++itrX) {
			auto itrY = itrX;
			if (itrX->second == 1) {
				++itrY;
			}

			for (; itrY != mp.end(); ++itrY) {
				int conflg = 0;

				conflg += connectfun(itrX->first, itrY->first);
				conflg += connectfun(itrY->first, itrX->first);

				if (itrX->first == itrY->first) {
					//排列组合
					connect += (itrX->second * (itrX->second - 1)) * conflg / 2;
				} else {
					connect += itrX->second * itrY->second * conflg;
				}
			}
		}
		return connect;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> ppp{ 16, 17, 18 };
	auto ret = s.numFriendRequests(ppp);
	// printf("%s\n", ret.c_str());
}
