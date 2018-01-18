class Solution {
public:
    int rectCover(int number) {
        if (number == 0) {
            return 0;
        }
        if (number == 1) {
            return 1;
        }
        if (number == 2) {
            return 2;
        }

        int fa = 1;
        int fb = 2;
        int fn;
        for (int i = 3; i <= number; i++) {
            fn = fa + fb;
            fa = fb;
            fb = fn;
        }
        return fn;
    }
};