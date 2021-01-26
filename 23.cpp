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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];

        auto cmp = [](ListNode* a, ListNode* b) {
            if (a==NULL)
                return true;
            if (b==NULL)
                return false;
            return a->val>b->val;
        };
        ListNode head(0);
        ListNode * ret = &head;
        make_heap(lists.begin(), lists.end(), cmp);

        while(lists[0]!=NULL){
            ret->next = lists[0];
            lists[0] = lists[0]->next;
            ret = ret->next;
            pop_heap(lists.begin(), lists.end(), cmp);
            push_heap(lists.begin(), lists.end(), cmp);
        }

        return head.next;
    }
};



int main(int argc,char ** argv)
{
    Solution s;
    vector<ListNode*>nd({0,0,0});
    auto ret = s.mergeKLists(nd);
}



