class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;

        string ans;

        for (int i = 0; i < s.size(); i++) {
            int x = target[i] - 'a';

            if (cnt[x]) {
                ans += target[i];
                cnt[x]--;
            } else {
                for (int c = x + 1; c < 26; c++) {
                    if (cnt[c]) {
                        string res = ans;
                        res += char('a' + c);
                        cnt[c]--;

                        for (int j = 0; j < 26; j++)
                            while (cnt[j]--)
                                res += char('a' + j);

                        return res;
                    }
                }
                break;
            }
        }

        for (int i = ans.size() - 1; i >= 0; i--) {
            cnt[ans[i] - 'a']++;

            for (int c = ans[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c]) {
                    string res = ans.substr(0, i);
                    res += char('a' + c);
                    cnt[c]--;

                    for (int j = 0; j < 26; j++)
                        while (cnt[j]--)
                            res += char('a' + j);

                    return res;
                }
            }
        }

        return "";
    }
};