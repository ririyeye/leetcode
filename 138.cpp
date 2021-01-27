#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node ret(0);
        Node *tmp = &ret;

        while(head){
            tmp->next = new Node(head->val);
            tmp = tmp->next;
            tmp->random = head->random;
            table[head] = tmp;
            head = head->next;
        }

        tmp = ret.next;
        while(tmp){
            if(tmp->random){
                auto itr = table.find(tmp->random);
                if(itr != table.end()){
                    tmp->random = itr->second;
                }
            }
            tmp = tmp->next;
        }
        return ret.next;
    }

private:
    //第一个参数是原来输入的节点
    //第二个参数是复制的节点
    std::unordered_map<Node *,Node *> table;

};

int main(int argc,char ** argv)
{
    Solution s;
    vector<int> ppp({1,2,3,4,5});

}
