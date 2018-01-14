class Solution {
public:
	void replaceSpace(char *str,int length) {
        int spaces = 0;
        char *p = str;

        while (*p != '\0') {
            if (*p == ' ') {
                spaces++;
            }
            p++;
        }

        char *q = p + 2*spaces;
        while (p != str) {
            if (*p == ' ') {
                *q = '0';
                q--;
                *q = '2';
                q--;
                *q = '%';
                q--;
                p--;
            }
            else {
                *q = *p;
                q--;
                p--;
            }
        }
        if (*p == ' ') {
            *q = '0';
            q--;
            *q = '2';
            q--;
            *q = '%';
            q--;
        }
    }
};
