class Solution {
public:
    void add(string a, string b, string &ans) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = a.size();
        int m = b.size();

        int i = 0;
        int carry = 0;

        while (i < m) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;

            ans += (sum % 2) + '0';
            carry = sum / 2;

            i++;
        }

        while (i < n) {
            int sum = (a[i] - '0') + carry;

            ans += (sum % 2) + '0';
            carry = sum / 2;

            i++;
        }


        if (carry) {
            ans += '1';
        }


        reverse(ans.begin(), ans.end());
    }

    string addBinary(string a, string b) {
        string ans;

        if (a.size() > b.size()) {
            add(a, b, ans);
        } else {
            add(b, a, ans);
        }

        return ans;
    }
};