#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
	string truncateSentence(string s, int k)
	{
		if (k <= 0)
			return "";

		int index = 0;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == ' ') {
				if(--k == 0) {
					s.resize(i);
					return s;
				}
			}
		}
		return s;
	}
};

int main(int argc, char **argv)
{
	string mag = "chopper is not a tanuki";
	Solution s;
	auto ret = s.truncateSentence(mag, 5);
	return 0;
}
