#include <math.h>
#include <stdio.h>
class Solution {
    public:
	int findNthDigit(int n)
	{
		int64_t dig = 0;
		int64_t start = 0;
		do {
			start = pow(10, dig);
			dig++;
			int64_t maxsize = 9 * start * dig;			
			if (n > maxsize) {
				n -= maxsize;
			} else {
				break;
			}
		} while (1);

		if (dig == 1) {
			return n;
		}
		n--;
		int64_t num = n / dig + start;
		int64_t p = n % dig;

		for (p++; p < dig; p++) {
			num /= 10;
		}

		return num % 10;
	}
};

int main()
{
	Solution s;
	int ret = s.findNthDigit(1000000000);
	printf("num = %d\n", ret);
	return 0;
}
