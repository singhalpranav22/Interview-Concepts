// Sum Of Fibonacci Numbers
// How many minimum numbers from fibonacci series are required such that sum of numbers should be equal to a given Number N?
// Note : repetition of number is allowed.

// Example:

// N = 4
// Fibonacci numbers : 1 1 2 3 5 .... so on
// here 2 + 2 = 4 
// so minimum numbers will be 2 

int Solution::fibsum(int A) {
    vector<int> v;
    v.push_back(1);v.push_back(2);
    for(int i=2;i<A+1;i++){
        int tp = v[i-1]+v[i-2];
        if(tp>A) break;
        v.push_back(tp);
    }
    int n=v.size();n-=1;
    int ans=0;
    while(A){
        if(v[n]<=A){
            A-=v[n];
            ans++;
        }
        n=lower_bound(v.begin(),v.begin()+n,A)-v.begin();
        if(v[n]>A) n--;
    }
    return ans;
}
