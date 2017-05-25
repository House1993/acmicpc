//
// Created by 房籽呈 on 2017/5/25.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/72730563
 */

/**
 * 利用数字个数优化 9ms
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        vector<int> ans{0};
        vector<int> number1 = convert(num1), number2 = convert(num2);
        counted[1] = number1;
        for (int i = 0; i < number2.size(); ++i) {
            if (number2[i] == 0) {
                continue;
            }
            int b = number2[i];
            if (counted[b].size() > 0) {
                add(ans, counted[b], i);
            } else {
                vector<int> tmp = multiply(number1, b);
                add(ans, tmp, i);
                counted[b] = tmp;
            }
        }
        return convert(ans);
    }

private:
    vector<int> counted[10];

    vector<int> convert(string num) {
        vector<int> number;
        for (int i = num.size() - 1; i >= 0; --i) {
            number.push_back(num[i] - '0');
        }
        return number;
    }

    string convert(vector<int> num) {
        stringstream ss;
        bool zero = true;
        for (int i = num.size() - 1; i >= 1; --i) {
            if (zero && num[i] == 0) {
                continue;
            } else {
                zero = false;
            }
            ss << num[i];
        }
        ss << num[0];
        return ss.str();
    }

    vector<int> multiply(vector<int> &num, int b) {
        vector<int> ans;
        int tmp = 0;
        for (int i = 0; i < num.size(); ++i) {
            tmp += b * num[i];
            ans.push_back(tmp % 10);
            tmp /= 10;
        }
        if (tmp != 0) {
            ans.push_back(tmp);
        }
        return ans;
    }

    void add(vector<int> &num1, vector<int> &num2, int pos) {
        for (int i = 0; i < pos + 1 - (int)num1.size(); ++i) {
            num1.push_back(0);
        }
        int tmp = 0;
        for (int i = pos; i < num1.size() || i < num2.size() + pos; ++i) {
            if (i < num2.size() + pos) {
                if (i >= pos) {
                    tmp += num2[i - pos];
                }
            } else {
                if (tmp == 0) {
                    break;
                }
            }
            if (i < num1.size()) {
                tmp += num1[i];
            } else {
                num1.push_back(0);
            }
            num1[i] = tmp % 10;
            tmp /= 10;
        }
        if (tmp != 0) {
            num1.push_back(tmp);
        }
    }
};

/**
 * string转成vector<int>直接计算 19ms
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans{0};
        vector<int> number1 = convert(num1), number2 = convert(num2);
        for (int i = 0; i < number1.size(); ++i) {
            vector<int> product = multiply(number1[i], i, number2);
            add(ans, product);
        }
        return convert(ans);
    }

private:
    vector<int> convert(string num) {
        vector<int> number;
        for (int i = num.size() - 1; i >= 0; --i) {
            number.push_back(num[i] - '0');
        }
        return number;
    }

    string convert(vector<int> num) {
        stringstream ss;
        bool zero = true;
        for (int i = num.size() - 1; i >= 1; --i) {
            if (zero && num[i] == 0) {
                continue;
            } else {
                zero = false;
            }
            ss << num[i];
        }
        ss << num[0];
        return ss.str();
    }

    vector<int> multiply(int num1, int zero, vector<int> &num2) {
        vector<int> ans;
        while (zero--) {
            ans.push_back(0);
        }
        int tmp = 0;
        for (int i = 0; i < num2.size(); ++i) {
            tmp += num1 * num2[i];
            ans.push_back(tmp % 10);
            tmp /= 10;
        }
        if (tmp != 0) {
            ans.push_back(tmp);
        }
        return ans;
    }

    void add(vector<int> &num1, vector<int> &num2) {
        if (num1.size() < num2.size()) {
            swap(num1, num2);
        }
        int tmp = 0;
        for (int i = 0; i < num1.size(); ++i) {
            tmp += num1[i];
            if (i < num2.size()) {
                tmp += num2[i];
            }
            num1[i] = tmp % 10;
            tmp /= 10;
        }
        if (tmp != 0) {
            num1.push_back(tmp);
        }
    }
};