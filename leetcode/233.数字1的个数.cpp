class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            count += (n/divider)*i + min(max(n%divider-i+1, 0LL), i);
        }
        return count;
    }
};
