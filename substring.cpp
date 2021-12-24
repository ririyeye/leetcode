
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

using namespace std;

class Solution {
    public:
	struct nod {
		nod(string &&instr, size_t innum)
			: str(instr), num(innum)
		{
		}
		nod(const nod &innod)
			: str(innod.str), num(innod.num), height(innod.height)
		{
		}

		string str;
		int num;
		int height;
	};

	string longestDupSubstring(string s)
	{
		vector<unique_ptr<nod> > sa;

		int len = s.size();
		for (size_t i = 0; i < len; i++) {
			sa.emplace_back(make_unique<nod>(s.substr(i, len - i), i));
		}

		auto cmpstr = [](unique_ptr<nod> &A, unique_ptr<nod> &B) {
			return A->str < B->str;
		};
		sort(sa.begin(), sa.end(), cmpstr);

		vector<int> rank(len);

		for(int i = 0 ; i < len ;i++) {
			rank[sa[i]->num] = i;
		}

		int min_hi = 0 ;

		for (int i = 0; i < len; i++) {

			int sa_index = rank[i];

			if(sa_index - 1 < 0) {
				sa[sa_index]->height = 0;
				continue;
			}

			min_hi -= 1;

			int init_pos = (min_hi - 1) < 0 ? 0 : (min_hi - 1);

			for (int pos = init_pos; pos < sa[sa_index]->str.size() && pos < sa[sa_index - 1]->str.size(); pos++) {
				if (sa[sa_index - 1]->str[pos] == sa[sa_index]->str[pos]) {
					min_hi = pos + 1;
				} else {
					break;
				}
			}
			sa[sa_index]->height = min_hi;
		}

		return "";
	}
};

int main(int argc, char **argv)
{
	string b = "aabaaaab";
	Solution s;
	auto ret = s.longestDupSubstring(b);
	return 0;
}
