#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

class Solution {
    public:
	vector<int> loudAndRich(vector<vector<int> > &richer, vector<int> &quiet)
	{
		vector<vector<int> > graph(quiet.size());

		for (auto &dat : richer) {
			graph[dat[1]].emplace_back(dat[0]);
		}

		vector<int> ret(quiet.size(), -1);
		function<void(int)> dfs = [&](int x) {
			if (ret[x] != -1) {
				return;
			}
			ret[x] = x;
			for (int y : graph[x]) {
				dfs(y);
				if (quiet[ret[y]] < quiet[ret[x]]) {
					ret[x] = ret[y];
				}
			}
		};

		for (int i = 0; i < quiet.size(); i++) {
			dfs(i);
		}

		return ret;
	}
};

int main(int argc, char **argv)
{
	vector<vector<int> > test = {
		{ 1, 0 },
		{ 2, 1 },
		{ 3, 1 },
		{ 3, 7 },
		{ 4, 3 },
		{ 5, 3 },
		{ 6, 3 },
	};
	vector<int> quiet = { 3, 2, 5, 4, 6, 1, 7, 0 };
	Solution s;
	auto ret = s.loudAndRich(test, quiet);
	return 0;
}
