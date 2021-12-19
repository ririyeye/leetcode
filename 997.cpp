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
	int findJudge(int n, vector<vector<int> > &trust)
	{
		vector<int> grp_trust(n);
		vector<int> grp_trusted(n);

		for (auto &tru : trust) {
			grp_trust[tru[0] - 1]++;

			grp_trusted[tru[1] - 1]++;
		}

		int ret = -1;
		for (int i = 0; i < n; i++) {
			if (grp_trust[i] == 0 && grp_trusted[i] == n - 1) {
				if (ret == -1) {
					return i + 1;
				}
			}
		}

		return ret;
	}
};

int main(int argc, char **argv)
{
	int angle = 32;
	vector<vector<int> > location = { { 1, 3 }, { 1, 4 }, { 2, 3 }, { 2, 4 }, { 4, 3 } };
	Solution s;
	auto ret = s.findJudge(4, location);
	return 0;
}
