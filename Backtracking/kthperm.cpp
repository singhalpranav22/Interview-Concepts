// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

 

// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"
// Example 3:

// Input: n = 3, k = 1
// Output: "123"
 

// Constraints:

// 1 <= n <= 9
// 1 <= k <= n!


class Solution {
public:
    string ans;
vector<int> dig;
int fact[51];
void find(int n,int k){
    if(n==1){
        ans+=to_string(dig[0]);
        return;
    }
    int pos = k/fact[n-1];
    if(k%fact[n-1]==0) pos--;
    k-=pos*fact[n-1];
    ans+=to_string(dig[pos]);
    dig.erase(dig.begin()+pos);
    find(n-1,k);
    
}
string getPermutation(int A, int B) {
    if(A>12){
        return to_string(INT_MAX);
    }
    ans="";
    dig.clear();
    fact[0]=1;
    for(int i=1;i<=9;i++){ fact[i]=fact[i-1]*i;
    }
    for(int i=1;i<=A;i++) dig.push_back(i);
    find(A,B);
    return ans;
}
};