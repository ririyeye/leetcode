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
	int numWaterBottles(int numBottles, int numExchange)
	{
		int drink_num = numBottles;
		int blank_bottles = numBottles;
		while (blank_bottles >= numExchange) {

			int change = blank_bottles / numExchange;
			int left = blank_bottles % numExchange;

			drink_num += change;
			blank_bottles = change + left;
		}

		return drink_num;
	}
};

int main(int argc, char **argv)
{
	int angle = 32;
	vector<int> location = { 33, 55 };
	Solution s;
	auto ret = s.numWaterBottles(9, 3);
	return 0;
}
