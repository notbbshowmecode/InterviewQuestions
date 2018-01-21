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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }

        ListNode* pPrev = nullptr;
        ListNode* pNode = pHead;
        while (pNode != nullptr) {
            ListNode* pNext = pNode->next;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }

        return pPrev;
    }
};