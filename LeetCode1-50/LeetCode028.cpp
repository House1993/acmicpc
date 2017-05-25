//
// Created by 房籽呈 on 2017/1/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54783105
 */

/**
 * kmp 版本
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int const slen = haystack.size(), plen = needle.size();
        int next[plen];
        get_nextval(needle, plen, next);
        return kmp(haystack, slen, needle, plen, next, 0);
    }

private:
    void get_nextval(string ptrn, int plen, int *nextval) {
        int i = 0;
        nextval[i] = -1;
        int j = -1;
        while (i < plen) {
            if (j == -1 || ptrn[i] == ptrn[j]) {
                ++i;
                ++j;
                if (ptrn[i] != ptrn[j]) nextval[i] = j;
                else nextval[i] = nextval[j];
            } else j = nextval[j];
        }
    }

    int kmp(string src, int slen, string patn, int plen, int const *nextval, int pos) {
        int i = pos;
        int j = 0;
        while (i < slen && j < plen) {
            if (j == -1 || src[i] == patn[j]) {
                ++i;
                ++j;
            } else j = nextval[j];
        }
        if (j >= plen) return i - plen;
        else return -1;
    }
};

/**
 * 偷懒版本……
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        return haystack.find(needle);
    }
};