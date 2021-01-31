#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
    public:
	string convert(string s, int numRows)
	{
        if(numRows <= 1)
		    return s;

		vector<string> grp(numRows);

		char *p = &s[0];
		int row = 0;
		int downflg = 1;
		while (*p) {
			grp[row].push_back(*p++);

			if (downflg) {
				if (++row == numRows) {
					row -= 2;
					downflg = 0;
				}
			} else {
				if (--row < 0) {
					downflg = 1;
					row = 1;
				}
			}
		}
		string res;
		for (int i = 0; i < grp.size(); i++) {
			res += grp[i];
		}
		return res;
	}
};

int main(int argc, char **argv)
{
	string str("AB");

	Solution s;
	auto ret = s.convert(str,3);
	//auto ret = s.findMedianSortedArrays(a, b);
	//printf("%f\n", ret);
}
