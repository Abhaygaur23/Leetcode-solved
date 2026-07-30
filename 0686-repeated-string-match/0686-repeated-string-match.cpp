class Solution {
public:
    vector<int> buildLPS(string &pat) {
        int m = pat.size();
        vector<int> lps(m, 0);

        int len = 0;
        int i = 1;

        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len == 0) {
                    lps[i] = 0;
                    i++;
                } else {
                    len = lps[len - 1];
                }
            }
        }

        return lps;
    }

    bool kmp(string &txt, string &pat) {
        vector<int> lps = buildLPS(pat);

        int i = 0, j = 0;
        int n = txt.size(), m = pat.size();

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m)
                return true;

            else if (i < n && txt[i] != pat[j]) {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int repeat = 1;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        if (kmp(temp, b))
            return repeat;

        temp += a;

        if (kmp(temp, b))
            return repeat + 1;

        return -1;
    }
};