/*
First Bad Version
Solution
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 
*/




// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int lower=0,upper=INT_MAX;
    public:
    
    int firstBadVersion(int n) {
        
        if(!isBadVersion(n-1) && isBadVersion(n))
        {
            return n;
        }else if(!isBadVersion(n) && isBadVersion(n+1))
        {
            return n+1;
        }
        else if(isBadVersion(n))
        {
            if(n<upper)
                upper = n;
            cout<<"UPPER->"<<upper<<endl;
            return firstBadVersion((lower/2)+(upper/2));
        }
        else
        {
            if(n>lower)
                lower = n;
            cout<<"Lower->"<<lower<<endl;
            return firstBadVersion((lower/2)+(upper/2));
        }
    }
};
