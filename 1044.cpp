
#include <math.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <math.h>
#include <stdint.h>

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    public:
	const uint32_t prime = 31;
	uint32_t get_my_hash(char *buff, int len)
	{
		uint32_t ret = 0;

		return ret;
	}

	int memstr(void *m1, void *m2, int len)
	{
		unsigned char *c1 = (unsigned char *)m1;
		unsigned char *c2 = (unsigned char *)m2;

		for (int i = 0; i < len; i++) {
			if (*c1 != *c2) {
				return -1;
			}
		}
		return 0;
	}

	//寻找某个长度下是否有重复
	int find_dup(vector<char> &trans, int len)
	{
		uint64_t hash_init = 0;
		uint64_t power = 1;
		for (int i = 0; i < len; i++) {
			hash_init = hash_init * prime + trans[i];
			power = power * prime;
		}

		unordered_set<uint64_t> maps;
		int tim = trans.size() - len + 1;

		maps.insert(hash_init);

		for (uint32_t index = 1; index < tim; index++) {
			hash_init = hash_init * prime - trans[index - 1] * power + trans[index + len - 1];
			auto itr = maps.find(hash_init);

			if (itr == maps.end()) {
				maps.insert(hash_init);
			} else {
				return index;
			}
		}
		return -1;
	}

	string longestDupSubstring(string s)
	{
		int len = s.size();
		vector<char> trans(s.size());
		for (int i = 0; i < len; i++) {
			trans[i] = s[i] - 'a';
		}

		int l = 0;
		int r = len - 1;
		int pos = -1;

		while (l <= r) {
			int mid = (l + r) / 2;
			int start = find_dup(trans, mid);
			if (start != -1) {
				len = mid;
				pos = start;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}

		if (pos == -1) {
			return "";
		} else {
			return s.substr(pos, len);
		}
	}
};

int main(int argc, char **argv)
{
	string b = "cdabcdab";
	Solution s;
	auto ret = s.longestDupSubstring(b);
	return 0;
}
