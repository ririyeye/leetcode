
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
	int repeatedStringMatch(const string &a, const string &b)
	{
		if (b == "") {
			return 0;
		}

		int sa = a.size();

		int sb = b.size();
		int ib = 0;
		for (int i = 0; i < sa; i++) {
			if (a[i] == b[0]) {
				int indexa = i;
				int indexb = 0;
				int times = 1;
				do {
					if (++indexb >= sb) {
						return times;
					}

					if (++indexa >= sa) {
						times++;
						indexa = 0;
					}

				} while (a[indexa] == b[indexb]);
			}
		}

		return -1;
	}
};

int main(int argc, char **argv)
{
	string a = "abcd";
	string b = "cdabcdab";
	Solution s;
	auto ret = s.repeatedStringMatch(a, b);
	return 0;
}
