/* 

Product of Array Except Self
Solution
Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l;
        int r[nums.size()];
        int cl=1;
        for(int i=0;i<nums.size();i++)
        {
            l.push_back(cl);
            cl = cl * nums[i];
        }
        cl = 1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            r[i] = cl;
            cl = cl * nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = l[i]*r[i];
        }
        return nums;
    }
};
