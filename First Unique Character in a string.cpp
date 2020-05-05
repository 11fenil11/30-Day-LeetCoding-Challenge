/*
First Unique Character in a String
Solution
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/


//My Solution
 class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m,p;
        vector<char> v;
        for(int i=0;i<s.length();i++)
        {
            p[s[i]] = i;
            if(m[s[i]] == 0)
            {
                v.push_back(s[i]);
            }
            m[s[i]]++;
            
        }
        for(auto n:v)
        {
            if(m[n] == 1)
            {
                return p[n];
            }
        }
        return -1;
    }
};
 
 
 //not Mine
 class Solution {
public:
    int firstUniqChar(string s) {
                ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a'] += 1;
        }
        
        for (int i = 0; i < s.size(); ++i) {
            if (count[s[i]-'a'] == 1)
                return i;
        }
        
        return -1;
    }
};
