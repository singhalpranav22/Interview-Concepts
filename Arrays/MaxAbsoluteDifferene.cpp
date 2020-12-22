// You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.
// f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

// For example,

// A=[1, 3, -1]

// f(1, 1) = f(2, 2) = f(3, 3) = 0
// f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
// f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
// f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

// So, we return 5.

int Solution::maxArr(vector<int> &a) {
    // |A[i] - A[j]| + |i - j| open mod you would find cases
    // Find max & min for both (A[i]+i) & (A[i]-i) each
    
    int mx1=INT_MIN;int mx2=INT_MIN;int mn1=INT_MAX;int mn2=INT_MAX;
    int n=a.size();
    if(n==0) return 1;
    for(int i=0;i<n;i++){
        int t1=a[i]+i;
        int t2=a[i]-i;
        if(t1>mx1) mx1=t1;
        if(t1<mn1) mn1=t1;
        if(t2>mx2) mx2=t2;
        if(t2<mn2) mn2=t2;
    }
    return max(mx1-mn1,mx2-mn2);
    
}
