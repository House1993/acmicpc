//
// Created by 房籽呈 on 2017/1/24.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/54707708
 */

class Solution {
public:
    vector <string> letterCombinations(string digits) {
        vector <string> res;
        if (!digits.size()) {
            return res;
        }
        res.push_back("");
        for (int i = 0; i < digits.size(); ++i) {
            res = grow(res, digits[i]);
        }
        return res;
    }

private:
    vector <string> grow(vector <string> fath, char son) {
        vector <string> res;
        switch (son) {
            case '1': {
                res = fath;
                break;
            }
            case '2': {
                for (string s : fath) {
                    res.push_back(s + 'a');
                    res.push_back(s + 'b');
                    res.push_back(s + 'c');
                }
                break;
            }
            case '3': {
                for (string s : fath) {
                    res.push_back(s + 'd');
                    res.push_back(s + 'e');
                    res.push_back(s + 'f');
                }
                break;
            }
            case '4': {
                for (string s : fath) {
                    res.push_back(s + 'g');
                    res.push_back(s + 'h');
                    res.push_back(s + 'i');
                }
                break;
            }
            case '5': {
                for (string s : fath) {
                    res.push_back(s + 'j');
                    res.push_back(s + 'k');
                    res.push_back(s + 'l');
                }
                break;
            }
            case '6': {
                for (string s : fath) {
                    res.push_back(s + 'm');
                    res.push_back(s + 'n');
                    res.push_back(s + 'o');
                }
                break;
            }
            case '7': {
                for (string s : fath) {
                    res.push_back(s + 'p');
                    res.push_back(s + 'q');
                    res.push_back(s + 'r');
                    res.push_back(s + 's');
                }
                break;
            }
            case '8': {
                for (string s : fath) {
                    res.push_back(s + 't');
                    res.push_back(s + 'u');
                    res.push_back(s + 'v');
                }
                break;
            }
            case '9': {
                for (string s : fath) {
                    res.push_back(s + 'w');
                    res.push_back(s + 'x');
                    res.push_back(s + 'y');
                    res.push_back(s + 'z');
                }
                break;
            }
            case '0': {
                for (string s : fath) {
                    res.push_back(s + ' ');
                }
                break;
            }
        }
        return res;
    }
};