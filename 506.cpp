#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct node1 {
	int score;
	int index;
};

class Solution {
    public:
	vector<string> findRelativeRanks(vector<int> &score)
	{
		vector<node1> tmp;
		tmp.reserve(score.size());

		for (int i = 0; i < score.size(); i++) {
			node1 n0;
			n0.score = score[i];
			n0.index = i;
			tmp.emplace_back(n0);
		}

		sort(tmp.begin(), tmp.end(), [](node1 &A, node1 &B) { return A.score > B.score; });

		vector<string> ret(score.size());

		for (int i = 0; i < score.size(); i++) {
			if (i > 2) {
				ret[tmp[i].index] = to_string(i + 1);
			} else if (i == 0) {
				ret[tmp[i].index] = "Gold Medal";
			} else if (i == 1) {
				ret[tmp[i].index] = "Silver Medal";
			} else {
				ret[tmp[i].index] = "Bronze Medal";
			}
		}
		return ret;
	}
};
int main()
{
	vector<int> test = { 5, 4, 3, 2, 1 };
	Solution s;
	auto ret = s.findRelativeRanks(test);
	return 0;
}
