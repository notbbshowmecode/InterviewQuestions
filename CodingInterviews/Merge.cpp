/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) {
            return pHead2;
        }
        if (pHead2 == nullptr) {
            return pHead1;
        }

        ListNode* pHead = pHead1;
        ListNode* p = pHead1->next;
        ListNode* q = pHead2;
        if (pHead1->val > pHead2->val) {
            pHead = pHead2;
            p = pHead1;
            q = pHead2->next;
        }

        ListNode* node = pHead;
        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                node->next = p;
                p = p->next;
            }
            else {
                node->next = q;
                q = q->next;
            }
            node = node->next;
        }
        if (p != nullptr) {
            node->next = p;
        }
        if (q != nullptr) {
            node->next = q;
        }

        return pHead;
    }
};