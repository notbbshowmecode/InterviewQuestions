class Solution {
public:
    bool equal(double x, double y, double delta) {
        if (x-y < delta && x-y > -delta) {
            return true;
        }
        return false;
    }

    double PowerWithUnsignedExponent(double base, unsigned int exponent) {
        if (exponent == 0) {
            return 1;
        }
        if (exponent == 1) {
            return base;
        }
        if (exponent == 2) {
            return base * base;
        }

        double power = PowerWithUnsignedExponent(base, exponent >> 1);
        power *= power;

        if (exponent & 1 == 1) {
            power *= base;
        }

        return power;
    }

    double Power(double base, int exponent) {
        if (equal(base, 0.0, 0.00000001) && exponent < 0) {
            return 0.0;
        }

        unsigned int unsignedExponent = (unsigned int) exponent;
        if (exponent < 0) {
            unsignedExponent = (unsigned int) (-exponent);
        }

        double power = PowerWithUnsignedExponent(base, unsignedExponent);
        if (exponent < 0) {
            power = 1.0 / power;
        }

        return power;
    }
   
};