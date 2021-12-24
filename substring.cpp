
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>
#include <stdint.h>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <string.h>

using namespace std;

class Solution {
    public:
	struct nod {
		nod(size_t innum)
			: num(innum)
		{
		}

		int num;
		int height;
	};

	string longestDupSubstring(string s)
	{
		vector<nod> sa;

		int len = s.size();
		for (size_t i = 0; i < len; i++) {
			sa.emplace_back(i);
		}

		auto cmpstr = [&](nod &A, nod &B) {
			return strcmp(&s[A.num], &s[B.num]) < 0 ? 1 : 0;
		};

		sort(sa.begin(), sa.end(), cmpstr);

		vector<int> rank(len);

		for (int i = 0; i < len; i++) {
			rank[sa[i].num] = i;
		}

		int min_hi = 0;

		for (int i = 0; i < len; i++) {
			int sa_index = rank[i];

			if (sa_index - 1 < 0) {
				sa[sa_index].height = 0;
				continue;
			}

			min_hi = min_hi - 1 < 0 ? 0 : min_hi - 1;

			int init_pos = (min_hi - 1) < 0 ? 0 : (min_hi - 1);

			for (int pos = init_pos; pos < (len - sa[sa_index].num) && pos < (len - sa[sa_index - 1].num); pos++) {
				if (s[sa[sa_index - 1].num + pos] == s[sa[sa_index].num + pos]) {
					min_hi = pos + 1;
				} else {
					break;
				}
			}
			sa[sa_index].height = min_hi;
		}

		return "";
	}
};

int main(int argc, char **argv)
{
	string b = "abcd";
	Solution s;
	auto ret = s.longestDupSubstring(b);
	return 0;
}
