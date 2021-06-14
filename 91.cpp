#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

class Solution {
    public:
	int numDecodings(string s)
	{
		if (s[0] == '0')
			return 0;

		int len = s.size();

		if (len == 1)
			return 1;

		vector<int> dp;
		dp.resize(len);

		dp[0] = 1;
		int a = checknum(&s[0]);
		int b = s[1] == '0' ? 0 : 1;
		dp[1] = a + b;

		for (int i = 2; i < len; i++) {
			if (s[i] != '0')
				dp[i] += dp[i - 1];
			if (checknum(&s[i - 1]))
				dp[i] += dp[i - 2];
		}

		return dp[len - 1];
	}

	inline int checknum(char *chr)
	{
		if (chr[0] == '1' || (chr[0] == '2' && chr[1] <= '6'))
			return 1;
		return 0;
	}
};

int main()
{
	string str("12");
	Solution s;
	cout << s.numDecodings(str) << endl;
}
