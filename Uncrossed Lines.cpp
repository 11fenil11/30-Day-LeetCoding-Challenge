/*
Uncrossed Lines
We write the integers of A and B (in the order they are given) on two separate horizontal lines.

Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

A[i] == B[j];
The line we draw does not intersect any other connecting (non-horizontal) line.
Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

Return the maximum number of connecting lines we can draw in this way.

 

Example 1:


Input: A = [1,4,2], B = [1,2,4]
Output: 2
Explanation: We can draw 2 uncrossed lines as in the diagram.
We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
Example 2:

Input: A = [2,5,1,2,5], B = [10,5,2,1,5,2]
Output: 3
Example 3:

Input: A = [1,3,7,1,7,5], B = [1,9,2,5,1]
Output: 2
 

Note:

1 <= A.length <= 500
1 <= B.length <= 500
1 <= A[i], B[i] <= 2000
   Hide Hint #1  
Think dynamic programming. Given an oracle dp(i,j) that tells us how many lines A[i:], B[j:] [the sequence A[i], A[i+1], ... and B[j], B[j+1], ...] are uncrossed, can we write this as a recursion?

*/



class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int> > a(A.size()+1);
        for(int i=0;i<=A.size();i++)
        {
            a[i].resize(B.size()+1);
            a[i][0] = 0;
        }
        for(int i=0;i<=B.size();i++)
        {
            a[0][i] = 0;
        }
        for(int i=1;i<=A.size();i++)
        {
            for(int j=1;j<=B.size();j++)
            {
                if(A[i-1]==B[j-1])
                {
                    a[i][j] = a[i-1][j-1] + 1;
                }else if(a[i-1][j] >= a[i][j-1])
                {
                    a[i][j] = a[i-1][j];
                }else
                {
                    a[i][j] = a[i][j-1];
                }
            }
        }
        return a[A.size()][B.size()];
    }
};
