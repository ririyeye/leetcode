#include <vector>
using namespace std;

class NumMatrix {
    public:
	vector<vector<int> > &refmat;
	NumMatrix(vector<vector<int> > &matrix)
		: refmat(matrix)
	{
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		int sum = 0;
		for (size_t r = row1; r <= row2; r++) {
			for (size_t c = col1; c <= col2; c++) {
				sum += refmat[r][c];
			}
		}
		return sum;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */