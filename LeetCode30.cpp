//
// Created by 房籽呈 on 2017/1/25.
//

class Solution {
public:
    vector<int> findSubstring(string s, vector <string> &words) {
        vector<int> ans;
        ans.clear();

        if (words.size() == 0) {
            return ans;
        }

        map<string, int> hash;
        hash.clear();
        for (int i = 0, idx = 0; i < words.size(); ++i) {
            if (!hash.count(words[i])) {
                hash[words[i]] = idx++;
            }
        }

        int *cnt = new int[hash.size()];
        memset(cnt, 0, sizeof(int) * hash.size());
        for (int i = 0, idx = 0; i < words.size(); ++i) {
            ++cnt[hash[words[i]]];
        }

        int *start = new int[s.size()];
        memset(start, -1, sizeof(int) * s.size());
        for (auto i = hash.begin(); i != hash.end(); ++i) {
            for (int idx = -1; idx + 1 < s.size();) {
                idx = s.find(i->first, idx + 1);
                if (idx != -1) {
                    start[idx] = i->second;
                } else {
                    break;
                }
            }
        }

        int len = words[0].size();
        for (int i = 0; i < len; ++i) {
            int tmpcnt = 0;
            int k = i;
            for (int j = i; j + len <= s.size(); j += len) {
                if ((j - k) / len == words.size()) {
                    if (start[k] != -1) {
                        --tmpcnt;
                        ++cnt[start[k]];
                    }
                    k += len;
                }
                if (start[j] != -1) {
                    --cnt[start[j]];
                    ++tmpcnt;
                    while (cnt[start[j]] < 0) {
                        if (start[k] != -1) {
                            --tmpcnt;
                            ++cnt[start[k]];
                        }
                        k += len;
                    }
                    if (tmpcnt == words.size()) {
                        ans.push_back(j - (tmpcnt - 1) * len);
                    }
                }
            }
            for (; k + len <= s.size(); k += len) {
                if (start[k] != -1) {
                    ++cnt[start[k]];
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};