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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode temp_node;
        ListNode* temp_ptr = &temp_node;
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                temp_ptr->next = head1;
                head1 = head1->next;
            }
            else
            {
                temp_ptr->next = head2;
                head2 = head2->next;
            }
            temp_ptr = temp_ptr->next;
        }
        if(head1 == NULL)
        {
            temp_ptr->next = head2;
        }
        else
        {
            temp_ptr->next = head1;
        }
        return temp_node.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];

        int midindex = lists.size() / 2;

        vector<ListNode *> Lgrp;
        vector<ListNode *> Rgrp;

        for (size_t i = 0; i < lists.size(); i++)
        {
            if(i < midindex)
                Lgrp.push_back(lists[i]);
            else
                Rgrp.push_back(lists[i]);
        }

        ListNode *Llist = mergeKLists(Lgrp);
        ListNode *Rlist = mergeKLists(Rgrp);

        return merge2Lists(Llist, Rlist);
    }
};



int main(int argc,char ** argv)
{
    Solution s;
    vector<ListNode*>nd({0,0,0});
    auto ret = s.mergeKLists(nd);
}



