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
	vector<vector<string> > partition(string s)
	{
	}
};

int main()
{
	string str = "aab";
	Solution s;
	auto strs = s.partition(str);
	for (auto &grp : strs) {
		cout << "ppp" << endl;
		for (auto &st : grp) {
			cout << st << endl;
		}
	}
}
