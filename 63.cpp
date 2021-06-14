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
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		auto &vec0 = obstacleGrid[0];
		if (vec0[0] == 1) {
			return 0;
		}

		vec0[0] = 1;
		for (int x = 1; x < n; x++) {
			if (vec0[x] == 0) {
				vec0[x] = vec0[x - 1];
			} else {
				vec0[x] = 0;
			}
		}

		for (int y = 1; y < m; y++) {
			if (obstacleGrid[y][0]) {
				obstacleGrid[y][0] = 0;
			} else {
				obstacleGrid[y][0] = obstacleGrid[y - 1][0];
			}

			for (int x = 1; x < n; x++) {
				if (obstacleGrid[y][x] == 1) {
					obstacleGrid[y][x] = 0;
				} else {
					obstacleGrid[y][x] = obstacleGrid[y - 1][x] + obstacleGrid[y][x - 1];
				}
			}
		}

		return obstacleGrid[m - 1][n - 1];
	}
};

int main()
{
	vector<vector<int> > ppp{ { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	Solution s;
	cout << s.uniquePathsWithObstacles(ppp) << endl;
}
