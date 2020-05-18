/*
 Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> m,pr;
        vector<int> ans;
        if(s.length() < p.length())
            return ans;
        for(char x : p)
        {
            m[x] = s.length();
            pr[x] = pr[x] + 1;
        }
        for(int i=0;i<=(s.length()-p.length());i++)
        {
            if(m[s[i]] != NULL)
            {
                // cout<<s[i]<<") val->"<<m[s[i]]<<" Pr=>"<<pr[s[i]]<<endl;
                int tmp = m[s[i]];
                if(pr[s[i]] == 1)
                {
                    m[s[i]] = m[s[i]] - 1;
                }else
                {
                    pr[s[i]] = pr[s[i]] - 1;
                }
                int k=1;
                while(k<p.length())
                {
                    if(m[s[i+k]] == tmp)
                    {
                        // cout<<s[i+k]<<") val->"<<m[s[i+k]]<<" Pr=>"<<pr[s[i+k]]<<endl;
                        // m[s[i+k]] = m[s[i+k]] -1;     
                        if(pr[s[i+k]] == 1)
                        {
                            m[s[i+k]] = m[s[i+k]] - 1;
                        }else
                        {
                            pr[s[i+k]] = pr[s[i+k]] - 1;
                        }
                    }else
                    {
                        // cout<<"EEEE KATA"<<endl;
                        for(int j=i;j<i+k;j++)
                        {
                            m[s[j]] = tmp;
                        }
                        break;
                    }
                    k++;
                }
                if(k==p.length())
                {
                    // cout<<"----Push->"<<i<<endl;
                    ans.push_back(i);
                }
                for(char x : p)
                {
                    pr[x] = 0;
                }
                for(char x : p)
                {
                    pr[x] = pr[x] + 1;
                }
            }
        }
        return ans;
    }
};


/*
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int> m,cr;
        vector<int> ans;
        if(s.length() < p.length())
            return ans;
        for(char x : p)
        {
            m[x] = s.length();
            cr[x] = cr[x] + 1;
        }
        for(int i=0;i<=(s.length()-p.length());i++)
        {
            if(m[s[i]] != NULL)
            {
                map<char,int> pr = cr;     
                
                // cout<<"\n"<<s[i]<<") val->"<<m[s[i]]<<" Pr=>"<<pr[s[i]];
                int tmp = m[s[i]];
                if(pr[s[i]] == 1)
                {
                    m[s[i]] = m[s[i]] - 1;
                }else
                {
                    pr[s[i]] = pr[s[i]] - 1;
                }
                int k=1;
                while(k<p.length())
                {
                    if(m[s[i+k]] == tmp)
                    {
                        // cout<<s[i+k]<<") val->"<<m[s[i+k]]<<" Pr=>"<<pr[s[i+k]];
                        // cout<<" Pr->"<<pr[s[i+k]];
                        // m[s[i+k]] = m[s[i+k]] -1;     
                        if(pr[s[i+k]] == 1)
                        {
                            cout<<i<<"Done!"<<endl;
                            m[s[i+k]] = m[s[i+k]] - 1;
                        }else
                        {
                            pr[s[i+k]] = pr[s[i+k]] - 1;
                        }
                    }else
                    {
                        // cout<<i<<")EEEE KATA"<<endl;
                        for(int j=i;j<i+k;j++)
                        {
                            m[s[j]] = tmp;
                        }
                        break;
                    }
                    k++;
                }
                if(k==p.length())
                {
                    cout<<"----Push->"<<i<<endl;
                    ans.push_back(i);
                }
                
            }
        }
        return ans;
    }
};
*/


/*
// Initialize
			std::vector<int> returnvec;
			std::unordered_map<char, size_t> letterBox;
			for (auto c : p) letterBox[c]++;
			std::queue<char> queue;
			
			// Visit all letters in the search string
			for (size_t i = 0; i < s.size(); i++)
			{
				auto it = letterBox.find(s[i]);
				if (it != letterBox.end()) // picket letter is in originals
				{
					if (it->second > 0)  // picket letter is still available in letterbox
					{
						queue.push(s[i]);
						letterBox[s[i]]--;
						if (queue.size() == p.size()) // we have a match
						{
							returnvec.push_back(i-p.size()+1);
							letterBox[queue.front()]++; 
							queue.pop();
						}
					}
					else // ran out of picket letter in letterbox, unwind queue until we this letter is found & put back in the queue
					{
						while (queue.front() != s[i])
						{
							letterBox[queue.front()]++;
							queue.pop();
						}
						queue.pop(); queue.push(s[i]);
					}
				}
				else  // picket letter not in originals, fully unwind queue & move on
				{
					while (!queue.empty()) 
					{
						letterBox[queue.front()]++; 
						queue.pop();
					}
				}
			}
			return returnvec;
*/
