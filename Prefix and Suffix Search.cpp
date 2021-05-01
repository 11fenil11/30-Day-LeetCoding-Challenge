class WordFilter {
public:
    map<string,int> m,rm;
    WordFilter(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                for(int k=0;k<words[i].length();k++)
                {
                    string tmp = words[i].substr(0,j+1) + "#" + words[i].substr((words[i].length() -1 - k),k+1); 
                    if(m[tmp] < i)
                    {
                        m[tmp] = i;    
                    }
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        int res = -1;
        string tmps = prefix + "#" + suffix;
        return m[tmps];
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
