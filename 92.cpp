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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode ret(0);
        ListNode *tmp = &ret;
        tmp->next = head;

        ListNode **tmpnode = (ListNode **)alloca(sizeof(ListNode **) * (n - m + 1));

        ListNode *breakhead = tmp;
        int breakflg = 0;
        for (int pos = 1; pos <= n; pos++)
        {
            if (tmp->next)
            {
                if (pos >= m)
                {
                    tmpnode[pos - m] = tmp->next;
                }else
                {
                    breakhead = tmp->next;
                }
            }else{
                breakflg = 1;
            }
            tmp = tmp->next;
        }

        if (breakflg == 0)
        {
            ListNode *tmpnxt = tmpnode[n - m]->next;

            int revindex = n - m + 1;
            while(revindex--){
                breakhead->next = tmpnode[revindex];
                breakhead = breakhead->next;
            }
            breakhead->next= tmpnxt;
        }

        // for (int i = 0; i < (n - m + 1);i++){
        //     ListNode *nod = tmpnode[i];
        //     printf("%d\n", nod->val);
        // }

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
    vector<int> ppp({1,2,3,4,5});
    auto lis = makelist(ppp);

    auto ret = s.reverseBetween(lis, 1, 4);
    prilist(ret);
}
