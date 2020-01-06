class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (n == 0) return str;
        if (str.empty()) return "";
        string res;
        res.append(str, n, str.length());
        res.append(str, 0, n);
        return res;
    }
};
