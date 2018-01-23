class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> s;
        vector<int>::iterator p = pushV.begin();
        vector<int>::iterator q = popV.begin();

        while (p != pushV.end()) {
            if (*p == *q) {
                p++;
                q++;
            }
            else {
                s.push(*p);
                p++;
            }
        }

        while (q != popV.end()) {
            if (s.empty() || s.top() != *q) {
                return false;
            }
            else {
                s.pop();
                q++;
            }
        }

        return true;
    }
};