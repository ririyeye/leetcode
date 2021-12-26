
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>
#include <stdint.h>

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
	vector<string> findOcurrences(string text, string first, string second)
	{
		vector<string> ret;

		string pattern = first + " " + second;
		int len = text.size();
		size_t pos = 0;
		while (pos < len) {
			pos = text.find(pattern, pos);
			if (pos == string::npos) {
				break;
			}

			if(pos > 0 && text[pos - 1] != ' ') {
				pos ++;
				continue;
			}

			int testpos = pos + pattern.size() + 1;

			if (testpos > len) {
				break;
			}

			while (testpos < len && text[testpos] == ' ') {
				testpos++;
			}

			int endpos = testpos + 1;
			while (endpos < len && text[endpos] != ' ') {
				endpos++;
			}
			ret.emplace_back(text,testpos,endpos - testpos);

			pos++;
		}

		return ret;
	}
};



int main(int argc, char **argv)
{
	Solution s;
	string a = "we we we we will rock you";
	string b = "we";
	string c = "we";
	auto ret = s.findOcurrences(a, b, c);
	return 0;
}
