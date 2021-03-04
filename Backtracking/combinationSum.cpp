// Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

//  Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The combinations themselves must be sorted in ascending order.
// CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
// The solution set must not contain duplicate combinations.
// Example,
// Given candidate set 2,3,6,7 and target 7,
// A solution set is:

// [2, 2, 3]
// [7]
//  Warning : DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.
// Example : itertools.combinations in python.
// If you do, we will disqualify your submission retroactively and give you penalty points. 

void find(set<vector<int> > & ans,vector<int> v,int i,int sum,int tar,int n,vector<int> curr)
{
    if(sum>tar || i==n) return;
    if(sum==tar){
        ans.insert(curr);
        return;
    }
    curr.push_back(v[i]);
    find(ans,v,i,sum+v[i],tar,n,curr);
    curr.pop_back();
    find(ans,v,i+1,sum,tar,n,curr);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    set<vector<int> > ans;
    sort(A.begin(),A.end());
    vector<int> curr;
    find(ans,A,0,0,B,A.size(),curr);
    vector<vector<int> > res;
    for(auto x : ans) res.push_back(x);
    return res;
}
