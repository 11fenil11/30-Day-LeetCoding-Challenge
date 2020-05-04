/*
Number Complement
Solution
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
 

Example 2:

Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Note:

The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/



Submission Detail
149 / 149 test cases passed.
Status: Accepted
Runtime: 0 ms
Memory Usage: 6.2 MB
*/

class Solution {
public:
    vector<int> v;
    void binary(int num)
    {
        if(num!=0)
        {
            int a,b;
            a=num%2;
            
            binary(num/2);
            // cout<<a;
            v.push_back(abs(a-1));
        }
    }
    
    int findComplement(int num) {
        
        int ans=0;
        binary(num);
        long long int i=1;
        for(int x=v.size()-1;x>=0;x--)
        {
            ans = ans + v[x]*i;
            i = i*2;
        }
        
        return ans;
    }
};

