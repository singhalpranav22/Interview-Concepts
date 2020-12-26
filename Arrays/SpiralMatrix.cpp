// Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.



// Input Format:

// The first and the only argument contains an integer, A.
// Output Format:

// Return a 2-d matrix of size A x A satisfying the spiral order.
// Constraints:

// 1 <= A <= 1000
// Examples:

// Input 1:
//     A = 3

// Output 1:
//     [   [ 1, 2, 3 ],
//         [ 8, 9, 4 ],
//         [ 7, 6, 5 ]   ]

// Input 2:
//     4

// Output 2:
//     [   [1, 2, 3, 4],
//         [12, 13, 14, 5],
//         [11, 16, 15, 6],
//         [10, 9, 8, 7]   ]

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<int> > generateMatrix(int a) {
    int arr[a][a];
    memset(arr,-1,sizeof(arr));
    int i=0;
    int j=0;
    int curr=1;
    while(1)
    {
        int f=0;
        while(j<a && j>=0 && arr[i][j]==-1)
        {
            arr[i][j]=curr;
            j++;
            curr++;
            f=1;
        }
        j--;
        i++;
        while(i<a && i>=0 && arr[i][j]==-1 )
        {
            arr[i][j]=curr;
            i++;
            curr++;
            f=1;
        }
        i--;
        j--;
         while(j<a && j>=0 && arr[i][j]==-1)
        {
            arr[i][j]=curr;
            j--;
            curr++;
            f=1;
        }
        j++;
        i--;
         while(i<a && i>=0 && arr[i][j]==-1 )
        {
            arr[i][j]=curr;
            i--;
            curr++;
            f=1;
        }
        i++;
        j++;
        if(f==0)
         break;
        
    }
    vector<vector<int> > v(a,vector<int> (a));
    for(int i=0;i<a;i++)
     for(int j=0;j<a;j++)
      v[i][j]=arr[i][j];
      
     return v;
}
int main(){
    int n=5;
    vector<vector<int> > v(n,vector<int> (n));
    v=generateMatrix(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cout<<v[i][j]<<" ";
        
        cout<<endl;
    }
}