// Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

// Example:

		
// Input: 	

// 1 2 3
// 4 5 6
// 7 8 9

// Return the following :

// [ 
//   [1],
//   [2, 4],
//   [3, 5, 7],
//   [6, 8],
//   [9]
// ]


// Input : 
// 1 2
// 3 4

// Return the following  : 

// [
//   [1],
//   [2, 3],
//   [4]
// ]

vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    vector<vector<int> > ans;
    int n=a[0].size();
    for(int k=0;k<n;k++)
    {
        vector<int> v;
        int i=0;
        int j=k;
        while(i<n && j>=0)
        {
            v.push_back(a[i][j]);
            i++;j--;
        }
        ans.push_back(v);
    }
    for(int k=1;k<n;k++)
    {
        int i=k;
        int j=n-1;
        vector<int> v;
        while(i<n && j>=0)
        {
            v.push_back(a[i][j]);
            i++;j--;
        }
        ans.push_back(v);
    }
    return ans;
}
