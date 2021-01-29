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
	ListNode *rotateRight(ListNode *head, int k)
	{
		ListNode *savehead = head;

		vector<ListNode *> tmp;
		while (head) {
			tmp.push_back(head);
			head = head->next;
		}
		if (tmp.size() <= 1) {
			return savehead;
		}

		k = k % tmp.size();
		if (k == 0)
			return savehead;

		tmp[tmp.size() - k - 1]->next = 0;
		tmp.back()->next = tmp[0];

		return tmp[tmp.size() - k];
	}
};