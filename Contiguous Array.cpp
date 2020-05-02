/*

Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        size_t sz = nums.size();
        if (sz <= 1) {
            return 0;
        }
        int zeroes = 0;
        int ones = 0;
        int maxLength = 0;
        std::map<int, int> positions;
        positions[0] = -1;
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == 0) {
                ++zeroes;
            } else {
                ++ones;
            }
            int diff = ones - zeroes;
            auto it = positions.find(diff);
            if (it == positions.end()) {
                positions[diff] = i;
            } else {
                int len = i - positions[diff];
                if (maxLength < len) {
                    maxLength = len;
                }
            }
        }
        return maxLength;
    }
};
