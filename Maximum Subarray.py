"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

I have used KADANE's algorithm. You can find that on : https://youtu.be/86CQq3pKSUw
"""


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_cr = nums[0]
        max_xx = nums[0]
        for i in range(1,len(nums)):
            max_cr = max(nums[i],max_cr+nums[i])
            if(max_cr > max_xx):
                max_xx = max_cr
        return max_xx
