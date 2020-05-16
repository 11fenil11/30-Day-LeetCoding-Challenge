/*
Maximum Sum Circular Subarray
Solution
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000
   Hide Hint #1  
For those of you who are familiar with the Kadane's algorithm, think in terms of that. For the newbies, Kadane's algorithm is used to finding the maximum sum subarray from a given array. This problem is a twist on that idea and it is advisable to read up on that algorithm first before starting this problem. Unless you already have a great algorithm brewing up in your mind in which case, go right ahead!
   Hide Hint #2  
What is an alternate way of representing a circular array so that it appears to be a straight array? Essentially, there are two cases of this problem that we need to take care of. Let's look at the figure below to understand those two cases:

   Hide Hint #3  
The first case can be handled by the good old Kadane's algorithm. However, is there a smarter way of going about handling the second case as well?

*/


class Solution {
public:
    int maxSubArray(std::vector<int>& A)
		{
			int currentSum = 0;
			int maxSum = A[0];// INT_MIN;
			for (auto v : A)
			{
				currentSum = std::max(v, currentSum+v);
				maxSum = std::max(maxSum, currentSum);
			}
			return maxSum;
		}
		int minSubArray(std::vector<int>& A, int i , int j )
		{
			int currentSum = 0;
			int minSum = 0;// A[0];// INT_MAX;
			for (int k = i; k < j; k++)
			{
				currentSum = std::min(A[k], currentSum + A[k]);
				minSum = std::min(minSum, currentSum);
			}
			return minSum;
		}
		int maxSubarraySumCircular(std::vector<int>& A) 
		{
			// Sum
			int S = 0;
			for (auto v : A) S += v;

			// Max sub array, not split
			int max_nosplit = maxSubArray(A);

			// Max sub array, split1
			int minSubArr_nosplit1 = minSubArray(A,0,A.size()-1);
			int max_split1 = S - minSubArr_nosplit1;
			
			// Max sub array, split2
			int minSubArr_nosplit2 = minSubArray(A, 1, A.size());
			int max_split2 = S - minSubArr_nosplit2;

			//auto old_count = A.size();
			//A.reserve(2 * old_count);
			//std::copy_n(A.begin(), old_count, std::back_inserter(A));
			return std::max(max_nosplit,std::max(max_split1,max_split2));
		}
};
