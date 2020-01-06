// 题目：151. 翻转字符串里的单词
// 给定一个字符串，逐个翻转字符串中的每个单词。
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//

class Solution {
public:
    string reverseWords(string str) {
        string res;
        if (str.empty()) return res;
        stack<string> s;
        string stemp;
        for (int i = 0; i < str.length(); i++) {
            while (str[i] != ' ' && i < str.length()) {
                stemp.push_back(str[i]);
                i++;
            }
            if (!stemp.empty()) {
                s.push(stemp);
                stemp.clear();
            }
        }

        while (!s.empty()) {
            res.append(s.top());
            if (s.size() != 1) {
                res.append(" ");
            }
            s.pop();
        }
        return res;
    }
};


// 思路2：先翻转整个句子，再翻转每个单词中字符的顺序
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());                        //整体反转
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') start++;//首空格
        while (end >= 0 && s[end] == ' ') end--;            //尾空格
        if (start > end) return "";                         //特殊情况

        for (int r = start; r <= end;) {                    //逐单词反转
            while (s[r] == ' '&& r <= end) r++;
            int l = r;
            while (s[l] != ' '&&l <= end) l++;
            reverse(s.begin() + r, s.begin() + l);
            r = l;
        }

        int tail = start;                                   //处理中间冗余空格
        for (int i = start; i <= end; i++) {
            if (s[i] == ' '&&s[i - 1] == ' ') continue;
            s[tail++] = s[i];
        }
        return s.substr(start, tail - start);
    }
};
