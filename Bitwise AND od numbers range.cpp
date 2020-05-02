/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
*/







class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long int ans=m;
        if(m==n)
        {
            return m&n;
        }
        for(long long int i=m+1;i<=n;i++)
        {
            ans = ans & i;
            if(ans==0)
            {
                break;
            }
        }
        return ans;
    }
};
