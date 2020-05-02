/*

Perform String Shifts
Solution
You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

 

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"
Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
 

Constraints:

1 <= s.length <= 100
s only contains lower case English letters.
1 <= shift.length <= 100
shift[i].length == 2
0 <= shift[i][0] <= 1
0 <= shift[i][1] <= 100

*/
#include<algorithm>
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int sh=0;
        for(long long i = 0;i<shift.size();i++)
        {
            if(shift[i][0] == 0)
            {
                sh = sh + shift[i][1];
            }else
            {
                sh = sh - shift[i][1];
            }
        }
        // cout<<"SH="<<sh<<endl;
        string res;
        
        if(sh>0)
        {
            sh = sh % s.length();
            while(res.length()<s.length())
            {
                if(sh==s.length())
                {
                    sh=0;
                }
                res = res + s[sh];
                sh++;
            }
        }else if(sh<0)
        {
            sh = abs(sh);
            sh = sh % s.length();
            reverse(s.begin(),s.end());
            while(res.length()<s.length())
            {
                if(sh==s.length())
                {
                    sh=0;
                }
                res = res + s[sh];
                sh++;
            }
            reverse(res.begin(),res.end());
        }else
        {
            res = s;
        }
        return res;
    }
};


