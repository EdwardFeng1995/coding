// 题目：把只包含质因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// 思路1：三指针
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index < 1) return 0;
        vector<int> ugly = {1};
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        while (ugly.size() < index) {
            int a = ugly[i2]*2, b = ugly[i3]*3, c = ugly[i5]*5;
            int next = min(a, min(b,c));
            ugly.push_back(next);
            if (a == next) ++i2;
            if (b == next) ++i3;
            if (c == next) ++i5;
        }
        return ugly.back();
    }
};

// 剑指offer做法
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n < 1) return 0;
        vector<int> vec(n,0);
        vec[0] = 1;
        int nextUglyIndex = 1;
        int pMultiply2 = 0;
        int pMultiply3 = 0;
        int pMultiply5 = 0;
        while (nextUglyIndex < n) {
            int min = Min(vec[pMultiply2]*2, vec[pMultiply3]*3, vec[pMultiply5]*5);
            vec[nextUglyIndex] = min;
            while (vec[pMultiply2]*2 <= vec[nextUglyIndex])
                pMultiply2++;
            while (vec[pMultiply3]*3 <= vec[nextUglyIndex])
                pMultiply3++;
            while (vec[pMultiply5]*5 <= vec[nextUglyIndex])
                pMultiply5++;

            nextUglyIndex++;
        }
        return vec[n-1];

    }
    int Min(int n1, int n2, int n3) {
        int min = (n1 < n2) ? n1 : n2;
        min = (min < n3) ? min : n3;
        return min;
    }
};
