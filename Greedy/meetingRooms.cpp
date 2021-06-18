// Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.

// Where:

// A[i][0] = start time of the ith meeting.
// A[i][1] = end time of the ith meeting.
// Find the minimum number of conference rooms required so that all meetings can be done.



// Problem Constraints
// 1 <= N <= 10

// 0 <= A[i][0] < A[i][1] <= 2 * 109



// Input Format
// The only argument given is the matrix A.



// Output Format
// Return the minimum number of conference rooms required so that all meetings can be done.



// Example Input
// Input 1:

//  A = [      [0, 30]
//             [5, 10]
//             [15, 20]
//      ]

// Input 2:

//  A =  [     [1, 18]
//             [18, 23]
//             [15, 29]
//             [4, 15]
//             [2, 11]
//             [5, 13]
//       ]


// Example Output
// Output 1:

//  2
// Output 2:

//  4


// Example Explanation
// Explanation 1:

//  Meeting one can be done in conference room 1 form 0 - 30.
//  Meeting two can be done in conference room 2 form 5 - 10.
//  Meeting one can be done in conference room 2 form 15 - 20 as it is free in this interval.
// Explanation 2:

//  Meeting one can be done in conference room 1 from 1 - 18.
//  Meeting five can be done in conference room 2 from 2 - 11.
//  Meeting four can be done in conference room 3 from 4 - 15.
//  Meeting six can be done in conference room 4 from 5 - 13.
//  Meeting three can be done in conference room 2 from 15 - 29 as it is free in this interval.
//  Meeting two can be done in conference room 4 from 18 - 23 as it is free in this interval.

// Solution : Make starting and ending time in one array if it;s starting time increase the room, else if it's ending time deccrease room.
// Sort it as well
int Solution::solve(vector<vector<int> > &a) {
    vector<int> s;
    vector<int> e;
    for(int i=0;i<a.size();i++){
        s.push_back(a[i][0]);
        e.push_back(a[i][1]);
    }
    sort(s.begin(),s.end());
    sort(e.begin(),e.end());
    int i=0,j=0;
    int n= a.size();
    int ans=0;
    int mx=1;
    while(i<n && j<n){
        if(s[i]<e[j]){
            i++;
            ans++;
            mx=max(mx,ans);
        }
        else{
            j++;
            ans--;
        }
    }
    return mx;
}


//other code
bool comparator(pair<int,int>one, pair<int,int> two)
{
    if(one.first==two.first)
    {
        return (one.second>two.second);
    }
    return (one.first<two.first);
}


int Solution::solve(vector<vector<int> > &a) {
    vector< pair<int,int> >v;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(a[i][0],0));
        v.push_back(make_pair(a[i][1],1));
    }
    sort(v.begin(),v.end(),comparator);
    // for(int i=0;i<2*n;i++)
    // cout<<v[i].first<<" "<<v[i].second<<endl;
    
    int room=0;
    int mx=0;
    for(int i=0;i<2*n;i++)
    {
        if(v[i].second==0)
        {
            room++;
            mx=max(room,mx);
            
        }
        else
        room--;
        
    }
    return mx;
}