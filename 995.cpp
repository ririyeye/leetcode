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
	int minKBitFlips(vector<int> &A, int K)
	{
		int n = A.size();
		int cnt = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (A[i] >= 2)
				cnt--;
			if ((A[i] ^ cnt) & 1) {
				;
			} else {
				if (i + K > n)
					return -1;
				res++;
				cnt++;
				if (i + K < n)
					A[i + K] += 2;
			}
		}
		return res;
	}
};