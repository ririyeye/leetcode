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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return 0;

        ListNode ret(0);
        
        vector<ListNode *> grp;

        while (head)
        {
            grp.push_back(head);
            head = head->next;
        }
        auto cmp = [](ListNode *L, ListNode *R) {
            return L->val < R->val;
        };

        sort(grp.begin(), grp.end(), cmp);

        ListNode *tmp = &ret;
        ret.next = grp[0];

        for (int i = 0; i < grp.size();i++){
            tmp->next = grp[i];
            tmp = tmp->next;
        }
        tmp->next = 0;
        return ret.next;
    }
};


ListNode * makelist(vector<int>& dat)
{
    ListNode ret(0);
    ListNode *tmp = &ret;

    for(auto & p : dat){
        tmp->next = new ListNode(p);
        tmp = tmp->next;
    }
    return ret.next;
}

void prilist(ListNode * lis)
{
    while (lis)
    {
        printf("%d\n", lis->val);
        lis = lis->next;
    }
}


int main(int argc,char ** argv)
{
    Solution s;
    vector<int> ppp({4,2,1,3});
    auto lis = makelist(ppp);

    auto ret = s.insertionSortList(lis);
    prilist(ret);
}
