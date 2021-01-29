#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
    public:
	Node *flatten(Node *head)
	{
		if (!head)
			return head;
		Node ret;
		ret.next = head;
		flat(head);
		return ret.next;
	}

	Node *flat(Node *head)
	{
		while (true) {
			Node *next = head->next;
			Node *child = head->child;
			if (child) {
				head->next = head->child;
				head->child = 0;
				child->prev = head;

				Node *ret = flat(child);
				ret->next = next;
				if (next) {
					next->prev = ret;
				}
				head = ret;
			}

			if (next) {
				head = next;
			} else {
				return head;
			}
		}
	}
};