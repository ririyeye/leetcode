#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
	vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
	{
		int n = arr.size();
		auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
			return arr[x.first] * arr[y.second] > arr[x.second] * arr[y.first];
		};

		priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> q(cmp);

		for (int i = 1; i < n; i++) {
			q.emplace(0, i);
		}

		for (int i = 1; i < k; i++) {
			auto top = q.top();
			q.pop();
			if (top.first + 1 < top.second) {
				q.emplace(top.first + 1, top.second);
			}
		}
		return { arr[q.top().first], arr[q.top().second] };
	}
};