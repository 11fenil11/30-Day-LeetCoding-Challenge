/*
Majority Element
Solution
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
Submission Detail
46 / 46 test cases passed.
Status: Accepted
Runtime: 4 ms
Memory Usage: 19.9 MB
Submitted: 0 minutes ago

*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int a=0,cnt=0;
        for(auto& num:nums)
        {
            if(cnt==0)
            {
                a = num;
                cnt = 1;
            }else if(num == a)
            {
                cnt++;
            }else
            {
                cnt--;  
            }
        }
        return a;
    }
};
