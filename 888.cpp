#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Solution {
    public:
	vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
	{
		if (A.size() == 0 || B.size() == 0) {
			return vector<int>();
		}

		int sumA = 0;

		for (auto &p : A) {
			sumA += p;
		}

		int sumB = 0;

		for (auto &p : B) {
			sumB += p;
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		int diff = sumA - sumB;

		int indexA = 0, indexB = 0;

		while (indexA < A.size() && indexB < B.size()) {
			int testdiff = 2 * (A[indexA] - B[indexB]) - diff;

			if (testdiff == 0) {
				return vector<int>({ A[indexA], B[indexB] });
			} else if (testdiff > 0) {
				indexB++;
			} else {
				indexA++;
			}
		}

		return vector<int>();
	}
};

int main(int argc ,char ** argv)
{
	vector<int> A({ 2});
    vector<int> B({ 1, 3 });
    Solution s;
    auto ret = s.fairCandySwap(A, B);
    cout << ret.size() << endl;
}