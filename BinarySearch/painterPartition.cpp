// Given 2 integers A and B and an array of integars C of size N.

// Element C[i] represents length of ith board.

// You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

// Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

// 2 painters cannot share a board to paint. That is to say, a board
// cannot be painted partially by one painter, and partially by another.
// A painter will only paint contiguous boards. Which means a
// configuration where painter 1 paints board 1 and 3 but not 2 is
// invalid.
// Return the ans % 10000003



// Input Format

// The first argument given is the integer A.
// The second argument given is the integer B.
// The third argument given is the integer array C.
// Output Format

// Return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board % 10000003.
// Constraints

// 1 <=A <= 1000
// 1 <= B <= 10^6
// 1 <= C.size() <= 10^5
// 1 <= C[i] <= 10^6
// For Example

// Input 1:
//     A = 2
//     B = 5
//     C = [1, 10]
// Output 1:
//     50
// Explanation 1:
//     Possibility 1:- same painter paints both blocks, time taken = 55units
//     Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
//     There are no other distinct ways to paint boards.
//     ans = 50%10000003

// Input 2:
//     A = 10
//     B = 1
//     C = [1, 8, 11, 3]
// Output 2:
//     11


#define mod 10000003
#define ll long long

bool isValid(ll a,ll mid,ll b,vector<int> &v){
    ll num=1;
    ll curr=0;
    for(ll i=0;i<v.size();i++){
        ll val=v[i];
        curr+=val*b;
        if(curr>mid){
            num++;
            // cout<<v[i]*b<<" "<<mid<<endl;
            if(val*b>mid) return false;
            curr=val*b;
        }
        if(num>a) return false;
    }
    return true;
}
int Solution::paint(int a, int b, vector<int> &c) {
    ll sum=0;
    for(ll i=0;i<c.size();i++)
    {
        ll tp=c[i];
        ll pt=b;
    sum+=tp*pt;
    }
    // cout<<sum<<endl;
    ll l=0,r=sum;
    ll res=sum;
    while(l<=r)
    {
        ll two=2;
        ll mid = l - (l-r)/two;
        //  cout<<mid<<endl;
        if(isValid(a,mid,b,c)){
            //  cout<<"mid->"<<mid<<endl;
            res=mid;
            r=mid-1;
        } 
        else
         l=mid+1;
    }
    
    return (res%mod);
}
