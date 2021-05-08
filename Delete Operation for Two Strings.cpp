/*
Delete Operation for Two Strings

Solution
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4
 

Constraints:

1 <= word1.length, word2.length <= 500
word1 and word2 consist of only lowercase English letters.
Submission Detail
1306 / 1306 test cases passed.
Status: Accepted
Runtime: 8 ms
Memory Usage: 7.5 MB
Submitted: 0 minutes ago


*/

class Solution {
public:
    int minDistance(string str1, string str2) {
        int dp[str1.length()+1][str2.length()+1];
        for(int i=0;i<str1.length()+1;i++)
        {
            dp[i][0] = 0;
        }
        for(int i=0;i<str2.length()+1;i++)
        {
            dp[0][i] = 0;
        }
        for(int i=1;i<str1.length()+1;i++)
        {
            for(int j=1;j<str2.length()+1;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return  str1.length() - dp[str1.length()][str2.length()]+str2.length() - dp[str1.length()][str2.length()];
    }
};
