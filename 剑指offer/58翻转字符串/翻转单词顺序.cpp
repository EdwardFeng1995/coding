class Solution {
public:
    string ReverseSentence(string str) {
        string res;
        if (str.empty()) return res;
        stack<string> s;
        string stemp;
        for (int i = 0; i < str.length(); i++) {
            while (str[i] != ' ' && i < str.length()) {
                stemp.push_back(str[i]);
                i++;
            }
            s.push(stemp);
            stemp.clear();
            if (i != str.length()) {
                s.push(" ");
            }
        }
        while (!s.empty()) {
            res.append(s.top());
            s.pop();
        }
        return res;
        
    }
};
