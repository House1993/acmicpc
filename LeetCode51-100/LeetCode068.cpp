//
// Created by 房籽呈 on 2017/10/26.
//

/**
 * 题解：
 * http://blog.csdn.net/houserabbit/article/details/78353750
 */

class Solution {
public:
    vector <string> fullJustify(vector <string> &words, int maxWidth) {
        vector <string> ans;
        for (int i = 0; i < words.size();) {
            int count = words[i].size();
            int num = 1;
            int j = i + 1;
            while (j < words.size()) {
                if (count + words[j].size() + num > maxWidth) {
                    break;
                }
                count += words[j].size();
                ++num;
                ++j;
            }
            stringstream ss;
            if (j != words.size() && num > 1) {
                int space = (maxWidth - count) / (num - 1);
                int last = (maxWidth - count) - (num - 1) * space;
                ss << words[i++];
                while (i < j) {
                    for (int k = 1; k <= space; ++k) {
                        ss << ' ';
                    }
                    if (last) {
                        --last;
                        ss << ' ';
                    }
                    ss << words[i++];
                }
                ans.push_back(ss.str());
            } else {
                ss << words[i++];
                while (i < j) {
                    ss << ' ' << words[i++];
                }
                for (int k = count + num; k <= maxWidth; ++k) {
                    ss << ' ';
                }
                ans.push_back(ss.str());
            }
        }
        return ans;
    }
};