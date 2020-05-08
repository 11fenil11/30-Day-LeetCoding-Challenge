/*
Check If It Is a Straight Line
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 
Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
   Hide Hint #1  
If there're only 2 points, return true.
   Hide Hint #2  
Check if all other points lie on the line defined by the first 2 points.
   Hide Hint #3  
Use cross product to check collinearity.

Submission Detail
66 / 66 test cases passed.
Status: Accepted
Runtime: 16 ms
Memory Usage: 10 MB
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double m = ((double)coordinates[1][1] - (double)coordinates[0][1])/((double)coordinates[1][0] - (double)coordinates[0][0]);
        for(int i=0;i<coordinates.size()-1;i++)
        {
            if(((double)coordinates[i+1][1] - (double)coordinates[i][1])/((double)coordinates[i+1][0] - (double)coordinates[i][0])!=m)
            {
                return false;
            }
        }
        return true;
    }
};
