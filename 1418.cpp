#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>

using namespace std;
class Solution {
    public:
	vector<vector<string> > displayTable(vector<vector<string> > &orders)
	{
		unordered_set<string> foods;
		unordered_map<int, unordered_map<string, int> > menus;
		vector<vector<string> > ret;
		for (auto &order : orders) {
			menus[atoi(order[1].c_str())][order[2]]++;
			foods.insert(order[2]);
		}

		vector<string> head;
		head.push_back("Table");
		for (auto &food : foods) {
			head.push_back(food);
		}
		ret.push_back(head);
		for (auto &menu : menus) {
			vector<string> tmp;
			tmp.push_back(to_string(menu.first));
			for (auto &food : foods) {
				tmp.push_back(to_string(menu.second[food]));
			}
			ret.push_back(tmp);
		}
		return ret;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	vector<vector<string> > ppp{ { "David", "3", "Ceviche" }, { "Corina", "10", "Beef Burrito" }, { "David", "3", "Fried Chicken" }, { "Carla", "5", "Water" }, { "Carla", "5", "Ceviche" }, { "Rous", "3", "Ceviche" } };
	auto ret = s.displayTable(ppp);
	// printf("%s\n", ret.c_str());
}
