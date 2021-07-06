#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <stack>
#include <map>
using namespace std;
class Solution {
    public:
	map<string, int> zz;
	string countOfAtoms(string formula)
	{
		stack<int> ha;
		string s = "", d = "";
		int cnt = 1;
		for (auto i = formula.rbegin(); i != formula.rend(); ++i) { //从后往前遍历
			if (isdigit(*i))
				d = *i + d;
			else if (*i == ')') {
				int v = d == "" ? 1 : stoi(d);
				d = "";
				cnt *= v; //更新倍数
				ha.push(v); //入栈
			} else if (*i == '(') {
				cnt /= ha.top(); //更新倍数
				ha.pop(); //出栈
			} else {
				s += *i;
				if (*i >= 'A' && *i <= 'Z') {
					reverse(s.begin(), s.end());
					zz[s] += (d == "" ? 1 : stoi(d)) * cnt;
					s = "", d = ""; //完成一次记录后清空记录的数值
				}
			}
		}
		for (auto i : zz) {
			s += i.first;
			if (i.second > 1)
				s += to_string(i.second);
		}
		return s;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	string formula = "Mg(OH)2";
	auto ret = s.countOfAtoms(formula);
	printf("%s\n", ret.c_str());
}
