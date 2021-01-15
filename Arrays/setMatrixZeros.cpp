// Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

// Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.



// Input Format:

// The first and the only argument of input contains a 2-d integer matrix, A, of size M x N.
// Output Format:

// Return a 2-d matrix that satisfies the given conditions.
// Constraints:

// 1 <= N, M <= 1000
// 0 <= A[i][j] <= 1
// Examples:

// Input 1:
//     [   [1, 0, 1],
//         [1, 1, 1], 
//         [1, 1, 1]   ]

// Output 1:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [1, 0, 1]   ]

// Input 2:
//     [   [1, 0, 1],
//         [1, 1, 1],
//         [1, 0, 1]   ]

// Output 2:
//     [   [0, 0, 0],
//         [1, 0, 1],
//         [0, 0, 0]   ]

// This q could be done easily in O(n+m) space implementation but below is the O(1) space implementation

void Solution::setZeroes(vector<vector<int> > &a) {
    bool r=false,c=false; //stores whether the first row and the first column was 0 or not
    int m=a.size();
    if(m==0) return;
    int n=a[0].size();
    for(int i=0;i<n;i++)
    {
        if(a[0][i]==0){
            c=true;
            break;
        }
    }
    for(int i=0;i<m;i++)
    {
        if(a[i][0]==0)
        {
            r=true;
            break;
        }
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i][j]==0)
            {
                a[0][j]=0;
                a[i][0]=0;
            }
        }
    }
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i][0]==0 || a[0][j]==0)
             a[i][j]=0;
        }
    }
    if(r)
    {
        for(int i=0;i<m;i++)
         a[i][0]=0;
    }
    if(c)
    {
        for(int i=0;i<n;i++)
         a[0][i]=0;
    }
    return ;
}
