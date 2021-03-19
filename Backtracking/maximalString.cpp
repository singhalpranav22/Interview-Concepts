Problem Description

Given a string A and integer B, what is maximal lexicographical stringthat can be made from A if you do atmost B swaps.



Problem Constraints
1 <= |A| <= 9

A contains only digits from 0 to 9.

1 <= B <= 5



Input Format
First argument is string A.

Second argument is integer B.



Output Format
Return a string, the naswer to the problem.



Example Input
Input 1:

A = "254"
B = 1
Input 2:

A = "254'
B = 2


Example Output
Output 1:

 524
Output 2:

 542


Example Explanation
Explanation 1:

 Swap 2 and 5.
Explanation 2:

Swap 2 and 5 then swap 4 and 2.

// Brute force solution!
string mx="";
void find(string a,int k){
    if(k==0){
        if(mx<a) mx=a;
        return;
    }
    for(int i=0;i<a.length();i++){
        for(int j=i+1;j<a.length();j++){
            swap(a[i],a[j]);
            find(a,k-1);
            swap(a[i],a[j]);
        }
    }
}

string Solution::solve(string A, int B) {
    mx="";
    find(A,B);
    return mx;
}
