#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const unordered_set<int> prime_num = {
	2, 3, 5, 7, 11, 13, 17, 19
};

class Solution {
    public:
	int countPrimeSetBits(int left, int right)
	{
		int ret = 0;
		for (int num = left; num <= right; num++) {
			int pri_cnt = __builtin_popcount(num);
			if (prime_num.find(pri_cnt) != prime_num.end()) {
				ret++;
			}
		}
		return ret;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	vector<int> ppp{ 16, 17, 18 };
	auto ret = s.countPrimeSetBits(10, 15);
	printf("%d\n", ret);
}
