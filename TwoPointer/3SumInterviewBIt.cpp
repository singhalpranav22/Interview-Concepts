// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.

// Assume that there will only be one solution

// Example:
// given array S = {-1 2 1 -4},
// and target = 1.

// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int ans = 100000000;
    int f=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
        int a1=A[i];
        while(j<k)
        {
            if(abs(B-a1-A[j]-A[k])<abs(B-ans)) ans=a1+A[j]+A[k];
            if(a1+A[j]+A[k]==B)
            {
                f=1;
                break;
            }
            else if(a1+A[j]+A[k]<B)
              j++;
             else
              k--;
        }
        if(f==1) break;
    }
    return ans;
}
