#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
	int checkNULLs(vector<int> &arrs)
	{
		for (auto &dat : arrs) {
			if (dat > 0) {
				return 0;
			}
		}
		return -1;
	}

    public:
	bool canConstruct(string ransomNote, string magazine)
	{
		vector<int> tmp(26);

		for (auto chars : ransomNote) {
			tmp[chars - 'a']++;
		}

		for (auto chars : magazine) {
			if (--tmp[chars - 'a'] == 0) {
				if(0 != checkNULLs(tmp)){
					return true;
				}
			}
		}
		return false;
	}
};

int main(int argc, char **argv)
{
	string nots = "aa";
	string mag = "aab";
	Solution s;
	auto ret = s.canConstruct(nots, mag);
	return 0;
}
