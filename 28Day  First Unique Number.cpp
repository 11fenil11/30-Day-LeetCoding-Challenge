class FirstUnique {
public:
    unordered_map<int,int> mymap;
    queue<int> myqueue;
    FirstUnique(vector<int>& nums) {
        for(int x : nums)
        {
            mymap[x]+=1;
            myqueue.push(x);
        }
    }
    
    int showFirstUnique() {
        while(!myqueue.empty() && mymap[myqueue.front()]>1)
            myqueue.pop();
        if(myqueue.empty()) return -1;
        return myqueue.front();
    }
    
    void add(int value) {
        mymap[value]+=1;
        if(mymap[value]==1)
            myqueue.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
