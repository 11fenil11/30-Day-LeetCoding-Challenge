//Given a non-empty array of integers, every element appears twice except for one. Find that single one.


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int ,int> mp;
        map<int, int>::iterator it; 
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]] = mp[nums[i]]+1;
        }
        for(it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second == 1)
            {
                return it->first;        
                break;
            }
    	}
        return 0;
    }
};
