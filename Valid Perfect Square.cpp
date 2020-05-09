/*
Valid Perfect Square
Solution
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=2,cnt=0;
        int po = num;
        while(num!=1 && i<=po/2)
        {
            if(num%i == 0)
            {
                num = num / i;
                cnt++;
            }else
            {
                if(cnt%2!=0)
                {
                    return false;
                }else
                {
                    cnt = 0;
                }
                if(i==2)
                {
                    i = 3;
                }
                else
                {
                    i+=2;
                }
            }
        }
        if(num==1 && cnt%2==0)
            return true;
        else
            return false;
    }
};
