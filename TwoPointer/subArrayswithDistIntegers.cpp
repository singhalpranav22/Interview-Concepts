// important q
Subarrays with distinct integers!
Asked in:  
uber
Problem Description

Given an array A of positive integers,call a (contiguous,not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly B.

(For example: [1, 2, 3, 1, 2] has 3 different integers 1, 2 and 3)

Return the number of good subarrays of A.



Problem Constraints
1 <= |A| <= 40000

1 <= A[i] <= |A|

1 <= B <= |A|



Input Format
The first argument given is the integer array A.

The second argument given is an integer B.



Output Format
Return an integer denoting the number of good subarrays of A.



Example Input
Input 1:

 A = [1, 2, 1, 2, 3]
 B = 2
Input 2:

 A = [1, 2, 1, 3, 4]
 B = 3


Example Output
Output 1:

 7
Output 2:

 3


Example Explanation
Explanation 1:

  Subarrays formed with exactly 2 different integers: [1, 2], [2, 1], [1, 2], [2, 3], [1, 2, 1], [2, 1, 2], [1, 2, 1, 2].
Explanation 2:

  Subarrays formed with exactly 3 different integers: [1, 2, 1, 3], [2, 1, 3], [1, 3, 4].


int helper(vector<int> &a, int b){
    int res=0;
    int left=0, right=0;
    map<int, int> m;
    while(right<a.size()){
        m[a[right]]++;
        while(m.size()>b){
            m[a[left]]--;
            if(m[a[left]]==0) m.erase(a[left]);
            left++;
        }
        res+=right-left+1;
        right++;
    }
    return res;
}

int Solution::solve(vector<int> &a, int b) {
    return helper(a, b)-helper(a, b-1);
}