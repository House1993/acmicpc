//
// Created by house on 1/9/17.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54289491
 */

class Solution {
public:
    string intToRoman(int num) {
        stringstream ss;
        int thousand = num / 1000;
        while (thousand--) {
            ss << "M";
        }
        func(ss, num / 100 % 10, "M", "D", "C");
        func(ss, num / 10 % 10, "C", "L", "X");
        func(ss, num % 10, "X", "V", "I");
        return ss.str();
    }

private:
    void func(stringstream &ss, int num, string ten, string five, string one) {
        if (num == 4) {
            ss << one << five;
        } else if (num == 9) {
            ss << one << ten;
        } else {
            if (num >= 5) {
                ss << five;
                num -= 5;
            }
            while (num--) {
                ss << one;
            }
        }
    }
};