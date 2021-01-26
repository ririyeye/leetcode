#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
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
    bool chklist(vector<ListNode*>& lists){
        for (auto & p : lists){
            if(p)
                return true;
        }
        return false;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode ret(0);
        ListNode *nxt = &ret;

        int tmpmin;
        int tmpindex;
        while (chklist(lists))
        {
            tmpmin = __INT_MAX__;
            for (int i = 0; i < lists.size(); i++)
            {
                if (lists[i])
                {
                    if (lists[i]->val < tmpmin)
                    {
                        tmpmin = lists[i]->val;
                        tmpindex = i;
                    }
                }
            }

            nxt->next = lists[tmpindex];
            lists[tmpindex] = lists[tmpindex]->next;
            nxt = nxt->next;
        }

        return ret.next;
    }
};



int main(int argc,char ** argv)
{
    Solution s;
    vector<ListNode*>nd({0,0,0});
    auto ret = s.mergeKLists(nd);
}



