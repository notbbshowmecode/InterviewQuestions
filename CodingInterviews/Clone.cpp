/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    void Copy(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        while (p != nullptr) {
            RandomListNode* node = new RandomListNode(p->label);
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
    }

    void Link(RandomListNode* pHead) {
        RandomListNode* p = pHead;
        while (p != nullptr) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
    }

    RandomListNode* Split(RandomListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) {
            return pHead;
        }

        RandomListNode* pClone = pHead->next;

        RandomListNode* p = pHead;
        RandomListNode* q = pClone;
        while (p != nullptr && q != nullptr) {
            p->next = p->next->next;
            if (q->next != nullptr) {
                q->next = q->next->next;
            }
            p = p->next;
            q = q->next;
        }

        return pClone;
    }

    RandomListNode* Clone(RandomListNode* pHead) {
        Copy(pHead);
        Link(pHead);
        return Split(pHead);
    }
};