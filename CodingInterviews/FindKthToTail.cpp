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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == nullptr || k == 0) {
            return nullptr;
        }

        ListNode* pFront = pListHead;
        for (unsigned int i = 1; i < k; i++) {
            if (pFront->next != nullptr) {
                pFront = pFront->next;
            }
            else {
                return nullptr;
            }
        }

        ListNode* pBack = pListHead;
        while (pFront->next != nullptr) {
            pFront = pFront->next;
            pBack = pBack->next;
        }

        return pBack;
    }
};