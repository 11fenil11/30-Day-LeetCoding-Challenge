/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.
Follow up:

Can you solve it in O(N) time and O(1) space?
*/


class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> tmp1,tmp2;
        for(long long int i=0;i<S.length();i++)
        {
            if(S[i] == '#')
            {
                if(tmp1.size()!=0)
                {
                    tmp1.pop_back();
                }
            }
            else
            {
                tmp1.push_back(S[i]);
            }
        }
        for(long long int i=0;i<T.length();i++)
        {
            if(T[i] == '#')
            {
                if(tmp2.size()!=0)
                {
                    tmp2.pop_back();    
                }
            }
            else
            {
                tmp2.push_back(T[i]);
            }
        }
        // string s1(tmp1.begin(),tmp1.end());
        // string s2(tmp2.begin(),tmp2.end());
        // cout<<s1<<" "<<s2;
        if(tmp1 == tmp2)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};


