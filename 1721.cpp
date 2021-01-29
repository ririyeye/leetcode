#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(0) {}
    ListNode(int x) : val(x), next(0) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
	ListNode *swapNodes(ListNode *head, int k)
	{
		vector<ListNode *> nodemap;

		ListNode ret(0);
		ret.next = head;

		while (head) {
			nodemap.push_back(head);
			head = head->next;
		}

		if (nodemap.size() >= k) {
			auto &a = nodemap[k - 1];
			auto &b = nodemap[nodemap.size() - k];

			swap(a->val, b->val);
		}
		return ret.next;
	}
};

int main(int argc, char **argv)
{
    Solution s;
    vector<ListNode *> nd({0, 0, 0});
    //auto ret = s.swapNodes(nd);
}
