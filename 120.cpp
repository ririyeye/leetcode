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
	int minimumTotal(vector<vector<int> > &triangle)
	{
		int ymax = triangle.size();

		for (int y = ymax - 2; y >= 0; y--) {
			int xsize = triangle[y].size();
			for (int x = 0; x < xsize; x++) {
				triangle[y][x] += min(triangle[y + 1][x], triangle[y + 1][x + 1]);
			}
		}
		return triangle[0][0];
	}
};
int main()
{
	vector<vector<int> > triangle = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
	Solution s;
	cout << s.minimumTotal(triangle) << endl;
}
