
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
struct cmps {
	vector<int> sa;
	vector<int> rnk;
	vector<int> tmp;
	vector<int> height;
	void getsa(int n, char *str)
	{
		sa.resize(n + 1);
		rnk.resize(n + 1);
		tmp.resize(n + 1);

		int k;
		auto cmp = [&](int i, int j) {
			if (rnk[i] != rnk[j])
				return rnk[i] < rnk[j];
			int ri = (i + k <= n ? rnk[i + k] : -1);
			int rj = (j + k <= n ? rnk[j + k] : -1);
			return ri < rj;
		};

		for (int i = 1; i <= n; i++)
			sa[i] = i, rnk[i] = str[i - 1];
		for (k = 1; k <= n; k *= 2) {
			sort(&sa[1], &sa[1 + n], cmp);
			tmp[sa[1]] = 1;
			for (int i = 2; i <= n; i++)
				tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
			for (int i = 1; i <= n; i++)
				rnk[i] = tmp[i];
		}
	}

	void getheight(int n, char *str)
	{
		height.resize(n + 1);

		for (int i = 1; i <= n; i++)
			rnk[sa[i]] = i;
		int h = 0;
		height[1] = 0;
		for (int i = 1; i <= n; i++) {
			int j = sa[rnk[i] - 1];
			
			if (h > 0)
				h--;
			for (; j + h <= n && i + h <= n; h++){
				int la = j + h -1;
				int lb = i + h -1;
				if(la < 0)
					break;

				if (str[la] != str[lb])
					break;
			}

			height[rnk[i]] = h;
		}
	}
};
cmps cm;
class Solution {
    public:

	string longestDupSubstring(string s)
	{
		int len = s.size();

		cm.getsa(len, &s[0]);
		cm.getheight(len, &s[0]);
#if 1


		int max_height = 0;
		int max_index = 0;

		for (size_t i = 1; i <= len; i++) {
			if (cm.height[i] > max_height) {
				max_height = cm.height[i];
				max_index = cm.sa[i] - 1;
			}
		}

		if (max_height > 0) {
			return s.substr(max_index, max_height);
		} else {
			return "";
		}
#endif
	}
};

int main(int argc, char **argv)
{
	string b = "nnpxouomcofdjuujloanjimymadkuepightrfodmauhrsy";
	Solution s;
	auto ret = s.longestDupSubstring(b);
	return 0;
}
