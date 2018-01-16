/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* ptr = head;
        stack<int> stk;
        while (ptr != nullptr) {
            stk.push(ptr->val);
            ptr = ptr->next;
        }

        vector<int> vct;
        while (!stk.empty()) {
            vct.push_back(stk.top());
            stk.pop();
        }
        return vct;
    }
};