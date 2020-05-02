/*

Valid Parenthesis String
Solution
Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].

*/

class Solution {
public:
    bool checkValidString(string s) {
        map<char,int> c;
        vector<char> v;
        for(char x: s)
        {
            if(x == '(')
            {
                c[x] = c[x] + 1;
                v.push_back(x);
            }
            else if(x == '*')
            {
                c[x] = c[x] + 1;
                v.push_back(x);
            }else
            {
                if(c['('] >0)
                {
                    c['('] = c['('] - 1;
                    long long q = v.size()-1;
                    while(v[q] == '*')
                    {
                        q--;
                    }
                    v.erase(v.begin()+q);
                }
                else if(c['*'] > 0)
                {
                    c['*'] = c['*'] - 1;
                    long long q = v.size()-1;
                    while(v[q] == '(')
                    {
                        q--;
                    }
                    v.erase(v.begin()+q);
                }else
                {
                    return 0;
                }
            }
        }
        int fud=0;
        int res = 1;
        // for(char x:v)
        // {
            // cout<<" "<<x;
        // }
        if(c['(']!=0)
        {   
            res = 0;
            for(int i=v.size()-1;i>=0;i--)
            {
                if(v[i] == '*')
                {
                    fud = fud + 1; 
                }else if(v[i] == '(')
                {
                    c['('] = c['('] -1;
                    fud = fud -1;
                    if(fud < 0)
                    {
                        // cout<<"break"<<endl;
                        break;
                    }
                }
                if(c['('] == 0)
                {
                    res = 1;
                    break;
                }
            }
        }
        return res;
        
    }
};
