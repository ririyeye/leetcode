
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
	int minPathSum(vector<vector<int> > &grid)
	{
		int m = grid.size();
		int n = grid[0].size();

		for (int i = 1; i < n; i++) {
			grid[0][i] += grid[0][i - 1];
		}

		for (int y = 1; y < m; y++) {
			grid[y][0] += grid[y - 1][0];
			for (int x = 1; x < n; x++) {
				grid[y][x] += min(grid[y][x - 1], grid[y - 1][x]);
			}
		}

		return grid[m - 1][n - 1];
	}
};

int main()
{
	vector<vector<int> > ppp{ { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
	Solution s;
	cout << s.minPathSum(ppp) << endl;
}
