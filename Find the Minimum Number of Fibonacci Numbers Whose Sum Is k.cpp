/*
1414. Find the Minimum Number of Fibonacci Numbers Whose Sum Is K
Medium

25

5

Add to List

Share
Given the number k, return the minimum number of Fibonacci numbers whose sum is equal to k, whether a Fibonacci number could be used multiple times.

The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 , for n > 2.
It is guaranteed that for the given constraints we can always find such fibonacci numbers that sum k.
 

Example 1:

Input: k = 7
Output: 2 
Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
For k = 7 we can use 2 + 5 = 7.
Example 2:

Input: k = 10
Output: 2 
Explanation: For k = 10 we can use 2 + 8 = 10.
Example 3:

Input: k = 19
Output: 3 
Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 

Constraints:

1 <= k <= 10^9
*/

class Solution {
public:
    
    
    int findMinFibonacciNumbers(int k) {
        long long int i=k,cnt=0,a,b,x=2;
        vector<long long int> m;
        m.push_back(0);
        m.push_back(1);
        a=1;
        b=1;
        while(x<k)
        {
            x = a+b;
            m.push_back(x);
            a = b;
            b = x;
            // cout<<"\n ->"<<x;
        }
        for(long long int i = m.size()-1;i>=0;i--)
        {
            if((m[i]<=k) && (k-m[i]>=0))
            {
                // cout<<"k =>"<<k<<"  m[i]->"<<m[i]<<endl;
                k = k - m[i];
                cnt++;
            }
            if(k==0)
            {
                break;
            }
        }
        return cnt;
    }
};


