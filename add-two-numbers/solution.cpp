/**
 * Make sure you complie the source file with -std=c++11 option.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *		int val;
 *		ListNode *next;
 *		ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *l_ = new ListNode(0);
		ListNode *lp = l_;
		int tmp = 0, sum = 0;
		while (true) {
			sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + tmp;
			lp->val = sum % 10;
			tmp = sum < 10 ? 0 : 1;
			l1 = (l1 == NULL ? NULL : l1->next);
			l2 = (l2 == NULL ? NULL : l2->next);
			if (l1 == NULL && l2 == NULL && tmp == 0) break;
			lp->next = new ListNode(0);
			lp = lp->next;
		}
		return l_;
	}
};

#define delete_linked_list(p) {auto *t = p; while(t != NULL) {p = p->next; delete t; t = p;}}

int main(int argc, char **argv)
{
	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	auto *t1 = l1;

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	auto *t2 = l2;

	Solution s = Solution();
	ListNode *l_ = s.addTwoNumbers(l1, l2);
	auto *t_ = l_;

	for (;l_ != NULL;l_ = l_->next) {
		std::cout << l_->val << " ";
	}
	std::cout << std::endl;
	
	delete_linked_list(t1)
	delete_linked_list(t2)
	delete_linked_list(t_)
	return 0;
}
