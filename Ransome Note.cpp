/*
Ransom Note
Solution
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int,int> m;
        for(char x:magazine)
        {
            m[x] = m[x]+1;
        }
        for(char x:ransomNote)
        {
            if(m[x]>0)
            {
                m[x] = m[x] - 1;
            }else
            {
                return 0;
            }
        }
        return 1;
    }
};
