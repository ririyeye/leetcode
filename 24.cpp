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

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode ret(0);
        ret.next = head;
        ListNode *p1 = &ret;
        ListNode *p2;
        while (p1->next != NULL && p1->next->next != NULL)
        {
            p2 = p1->next;
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1->next->next = p2;
            p1 = p2;
        }
        return ret.next;
    }
};

int main(int argc,char ** argv)
{
    Solution s;

    //auto ret = s.swapPairs(nd);
}



